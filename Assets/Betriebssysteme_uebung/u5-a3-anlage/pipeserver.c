/*
 * Interprozesskommunikation über Named Pipes (FIFOs) - pipeserver.c
 *
 * Funktionsweise: Dieses Server-Programm erwartet von seinem Client über ein
 * von ihm angelegtes benanntes Pipe eine Losung (Passwortsatz). Nach
 * (erfolgreicher) Überpruefung verrät der Server ein Geheimnis. Anschließend
 * löscht er das Pipe wieder.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char buffer[30];

#define	SECRET "xxx ..."

int main() {
	// Erzeugen der Named Pipe
	printf("Server: Erzeuge Named Pipe (FIFO).\n");
	int rw = mkfifo("P1", 0666); // erstellt PIPE bei const char *pathname hier P1, mit mode mode_t mode = 0_RDWR /erlaubt lesen und schreiben

	if (rw >= 0) {
		printf("        OK.\n\n");
	}

	// Öffnen der Pipe zum Lesen
	printf("Server: Öffne Pipe zum Lesen.\n");
	int id_p = open("P1", O_RDONLY);

	if (id_p >= 0) {
		printf("        OK.\n\n");
	}

	// Losung empfangen
	printf("Server: Warte auf Losung.\n");
	int result_read = read(id_p, buffer, sizeof(buffer));

	if (result_read > 0) {
		printf("        Losung empfangen.\n\n");
		printf("Received: %s\n", buffer);
	}

	// Vergleich
	if (strncmp(buffer, "<Schluessel>", strlen("<Schluessel>")) == 0) { // int strncmp(const char *str1, const char *str2, size_t n)
		printf("Server: Losung ist korrekt. Übergebe jetzt das Geheimnis.\n\n");

		// Öffnen der Pipe zum Schreiben
		printf("Server: Öffne dazu Pipe nur zum Schreiben.\n");
		close(id_p);

		id_p = open("P1", O_WRONLY);

		if (id_p >= 0) {
			printf("        OK.\n");
		}

		// Übergeben des Geheimnisses
		int result_write = write(id_p, SECRET, strlen(SECRET));

		if (result_write > 0) {
			printf("        OK.\n\n");
		}
	}
	else {
		printf("Server: Das war falsch.\n");
	}

	sleep(5);

	// Vernichte Pipe
	unlink("P1");

	printf("Server: Ende.\n");

	return 0;
}
