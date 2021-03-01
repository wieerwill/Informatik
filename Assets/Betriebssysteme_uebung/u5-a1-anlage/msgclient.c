/*
 * Interprozesskommunikation über Message Queues - msgclient.c
 *
 * Funktionsweise: Der Client schickt eine Losung an einen Server. Falls die
 * Losung die vom Server erwartete war, gibt letzterer dem Client sein
 * Geheimnis preis.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGSIZE 100
key_t key = 1337; 
int msgflg = 0666; 

// Typdefinition für Message Queue (muss explizit geschehen, da noch nicht
// vorhanden)
struct message {
	long msgType;
	char msgText[MSGSIZE];
};

// char CODEWORD[] = "<Losung>";
char CODEWORD[] = "Losung";

int main() {
	struct message msg_snd;
	struct message msg_rcv;

	// Verbinden mit Message-Queue des Servers
	printf("Client: Verbinde mich mit Message Queue.\n");
	int id_q = msgget(key, msgflg);

	if (id_q >= 0) {
		printf("        OK.\n\n");
	}

	// Absenden des Codeworts
	printf("Client: Sende Codewort an den Server.\n");
	msg_snd.msgType = 5;
	strcpy(msg_snd.msgText, CODEWORD);

	int result_snd = msgsnd(id_q, &msg_snd, MSGSIZE, 0);

	if (result_snd >= 0) {
		printf("        OK.\n\n");
	}
	
	// Empfangen der Antwort
	printf("Client: Warte auf Geheimnis.\n");

	// Abholen des Geheimnisses aus der Message-Queue
	int result_rcv = msgrcv(id_q, &msg_rcv, MSGSIZE, 6, 0);

	if (result_rcv >= 0) {
		printf("        Geheimnis erhalten.\n\n");
	}

	// Ausgabe des Geheimnisses
	printf("Client: Das Geheimnis lautet: '%s'.\n\n", msg_rcv.msgText);

	printf("Client: Ende.\n");

	return 0;
}
