/*
 * Interprozesskommunikation über Shared Memory - shmserver.c
 *
 * Funktionsweise: Das Programm kommuniziert mit einem Server mittels Shared
 * Memory und fragt mit einem Passwortsatz nach einem Geheimnis. Der Server
 * hinterlegt die Antwort ebenfalls im Shared-Memory-Bereich. Dabei müssen beide
 * Kommunikationspartner jeweils mit Semaphoren den Ablauf ihrer Kommunikation
 * steuern.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

// SHM
#define SHMKEY 1337
#define SHMSIZE 256

// SEM
#define RSEMKEY 100
#define SSEMKEY 101

#define SECRET "xxx..."
#define Losung "Losung"

struct sembuf sb[1];
int rsem_id, ssem_id;
char *sbuf; 



int main() {
	// Erzeugen eines Shared-Memory-Segments 
	printf("Server: Erzeuge Shared-Memory-Segment.\n");
	int id_shm = shmget(SHMKEY, SHMSIZE, IPC_CREAT|0666);

	if (id_shm >= 0) {
		printf("        OK.\n\n");
	}

	// Anhängen des Shared-Memory-Segments
	printf("Server: Hänge Shared-Memory-Segment an.\n");
	sbuf = shmat(id_shm, 0, 0);

	if (sbuf >= 0) {
		printf("        OK.\n\n");
	}

	// Erzeugen Semaphore
	ssem_id = semget(SSEMKEY, 1, IPC_CREAT|0666);
	rsem_id = semget(RSEMKEY, 1, IPC_CREAT|0666);
		
	semctl(ssem_id, 0, SETVAL, 0);
	semctl(rsem_id, 0, SETVAL, 0);

	printf("Server: Warte auf Semaphor.\n\n");
	sb[0].sem_num = 0;
	sb[0].sem_op = -1;
	sb[0].sem_flg = SEM_UNDO;
	semop(ssem_id, sb, 1);

	// Warten bis der Client geschrieben hat
	// Synchronisation
	printf("Server: Die Losung des Client lautet: '%s'.\n", sbuf);

	if (strncmp(sbuf, Losung, sizeof(Losung)) == 0 ) {
		printf("        Das war richtig.\n\n");
		printf("Server: Schreibe das Geheimnis in den Shared Memory.\n\n");
		snprintf(sbuf, SHMSIZE, "%s", SECRET);
	}
	else {
		printf("        Das war falsch.\n");
		snprintf(sbuf, 128, "Pech gehabt.");
	}

	printf("Server: Signalisiere, dass Client nun lesen kann.\n\n");
	sb[0].sem_num = 0;
	sb[0].sem_op = 1;
	sb[0].sem_flg = SEM_UNDO;
	semop(rsem_id, sb, 1);

	printf("Server: Ende.\n\n");

	shmdt(&id_shm);

	return 0;
}
