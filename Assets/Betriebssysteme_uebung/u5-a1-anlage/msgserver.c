/*
 * Interprozesskommunikation über Message Queues - msgcserver.c
 *
 * Funktionsweise: Der Server erzeugt eine Message Queue und erwartet über diese
 * die Losung eines Client. Falls die Losung mit der vom Server erwarteten
 * übereinstimmt, teilt der Server dem Client sein Geheimnis mit.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

#define MSGSIZE 100

#define	SECRET "GGG ..."
key_t key = 1337; 
int msgflg = IPC_CREAT | 0666; // Vergibt lese und schreibrechte an alle Nutzer, user  group others
struct message {
	long msgType;
	char msgText[MSGSIZE];
};

int main() {
	struct message msg_rcv;
	struct message msg_snd;

	// Erzeugen einer Message Queue
	printf("Server: Erzeuge Message Queue.\n");
	int id_q = msgget(key, msgflg);

	if (id_q >= 0) {
		printf("        OK.\n\n");
	}

	// Losung empfangen
	printf("Server: Warte auf Losung.\n");
	int result_rcv = msgrcv(id_q, &msg_rcv, MSGSIZE, 5, 0); // hier war 

	if (result_rcv >= 0) {
		printf("        Losung empfangen.\n\n");
	}

	// Vergleich
	if (strncmp(msg_rcv.msgText, "Losung", strlen("Losung")) == 0) {
		printf("Server: Losung ist korrekt. Sende jetzt das Geheimnis.\n");

		// Senden des Geheimnisses
		msg_snd.msgType = 5;
		strcpy(msg_snd.msgText, SECRET);

		int result_snd = msgsnd(id_q, &msg_snd, MSGSIZE, 0);

		if (result_snd >= 0) {
			printf("        OK.\n\n");
		}
	}
	else {
		printf("Server: Das war falsch.\n");
	}

	sleep(1);

	int result_ctl = msgctl(id_q, IPC_RMID, 0);

	if (result_ctl >= 0) {
		printf("Server: Message Queue gelöscht. Ende.\n\n");
		return 0; // alles OK
	}
	else {
		printf("Server: Message Queue löschen fehlgeschlagen. Ende.\n\n");
		return 10; // Fehler
	}
}
