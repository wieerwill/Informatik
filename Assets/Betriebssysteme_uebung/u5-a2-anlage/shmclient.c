/*
 * Interprozesskommunikation über Shared Memory - shmclient.c
 *
 * Funktionsweise: Das Programm kommuniziert mit einem Server mittels Shared
 * Memory und fragt mit einem Passwortsatz nach einem Geheimnis. Der Server
 * hinterlegt die Antwort ebenfalls im Shared-Memory-Bereich. Dabei müssen beide
 * Kommunikationspartner jeweils mit Semaphoren den Ablauf ihrer Kommunikation
 * steuern.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#define SHMSIZE 256
#define CODEWORD "Losung"

// statisch vereinbarte Schlüssel
const int shmKey = 1337;             // Schlüssel zum Benutzen des Shared Memory
const int readSemaphoreKey = 100;  // Schlüssel zum Benutzen der Semaphore
const int writeSemaphoreKey = 101; // Schlüssel zum Benutzen der Semaphore

const int textLen = 128;

int main(int arc, char** argv) {
   // dynamisch vergebene ID's
   // Benutzung der Semaphore und des Shared Memory vorbereiten
   int shmID = shmget(shmKey, 2 * textLen, 0);
   int readSemID = semget(readSemaphoreKey, 1, 0666);
   int writeSemID = semget(writeSemaphoreKey, 1, 0666);

   // Anhängen des Shared-Memory-Segments
   printf("Client: Hänge Shared-Memory-Segment an.\n\n");

   char *shm_ptr;
   shm_ptr = shmat(shmID, 0, 0);

   char *shm_ptr_alt;
	shm_ptr_alt = shm_ptr;

   // Absenden der Losung
   printf("Client: Sende meine Losung.\n\n");

   for (int i = 0; i <= strlen(CODEWORD); i++) {
      *shm_ptr++ = CODEWORD[i];
   }

   *shm_ptr = '\0';

   // Signal an den Server, dass die Daten jetzt lesbar sind
   struct sembuf semaphoreOperation;
	semaphoreOperation.sem_num = 0;
	semaphoreOperation.sem_op = 1;
	semaphoreOperation.sem_flg = SEM_UNDO;
	semop(writeSemID, &semaphoreOperation, 1);

   // Warten auf die Antwort (das Signal vom Server)
	semaphoreOperation.sem_num = 0;
	semaphoreOperation.sem_op = -1;
	semaphoreOperation.sem_flg = SEM_UNDO;
	semop(readSemID, &semaphoreOperation, 1);

   // Abolen des Geheimnisses und direkte Ausgabe
   char *sbuf; 
   sbuf = shmat(shmID,0,0);
   printf("Client: Das Geheimnis lautet: '%s'.\n\n", sbuf);

	printf("Client: Ende.\n\n");

   // Ausblenden des Shared Memory
   shmdt(&shmID);

   return 0;
}
