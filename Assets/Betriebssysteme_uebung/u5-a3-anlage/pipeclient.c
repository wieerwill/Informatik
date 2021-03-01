/*
 * Interprozesskommunikation über Named Pipes (FIFOs) - pipeclient.c
 *
 * Funktionsweise: Dieses Client-Programm meldet sich über ein benanntes Pipe
 * bei einem geeigneten Server und fragt mit einer Losung (Passwortsatz) nach
 * einem Geheimnis. Der Server kontrolliert die Losung. Ist diese korrekt,
 * antwortet der Server mit dem Geheimnis über die gleiche Pipe, welches auf
 * geeignete Weise vom Client gelesen werden kann.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

//char CODEWORD[] = "<Schluessel>";
char CODEWORD[] = "<Schluessel>";
char buffer[8];

int main() {
	// Öffnen der Named Pipe nur zum Schreiben
	printf("Client: Öffne Pipe nur zum Schreiben.\n");
	int id_p = open("P1", O_WRONLY); // const char *path, int oflag … / returnt einen Filedeskriptor

	if (id_p >= 0) {
		printf("        OK.\n\n");
	}

	// Absenden des Codeworts an Server
	printf("Client: Übergebe Codewort an den Server.\n");
	int result_write = write(id_p, CODEWORD, strlen(CODEWORD));

	if (result_write > 0) {
		printf("        OK.\n\n");
	}

	close(id_p);
	
	// Empfangen der Antwort
	printf("Client: Empfange Geheimnis.\n\n");

	// Öffnen der Pipe zum Lesen
	printf("Client: Öffne Pipe nur zum Lesen.\n");
	id_p = open("P1", O_RDONLY);

	if (id_p >= 0) {
		printf("        OK.\n");
	}

	// Lesen des Geheimnisses aus der Pipe
	int result_read = read(id_p, buffer, sizeof(buffer));

	if (result_read > 0) {
		printf("        Geheimnis erhalten.\n\n");
	}

	// Ausgabe des Geheimnisses
	printf("Client: Das Geheimnis lautet: '%s'.\n\n", buffer);

	printf("Client: Ende.\n");

	return 0;
}
