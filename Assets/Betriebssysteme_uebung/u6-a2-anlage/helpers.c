/*
 * This is just some code behind the curtain.
 * You really don't need to touch this.
 *
 */

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#include "helpers.h"

int do_quit = 0;
int do_reload = 0;

int load_config(void) {
	static char firsttime_message[] = "Loading";
	static char subsequent_message[] = "Reloading";
	static char *message = firsttime_message;

	fprintf(stderr, "%s configuration... ", message);
	fprintf(stderr, "done.\n");

	message = subsequent_message;
	do_reload = 0;

	return 1;
}

int main_loop(void) {
	fd_set rfds;
	struct timeval tv;
	int retval;
	char buf[1024];
	ssize_t len;

#if 0
	/* fork() to the background */
	if(fork()) return 0;
#endif

	fprintf(stderr, "I'm just a simple daemon, my PID is: %i\n",
		getpid());

	while (!do_quit) {
		/* 
		 * Let's just do our really simple job:
		 * Copy stdin to stdout (just another cat(1)).
		 */

		if (do_reload) {
			load_config();
		}

		/* Watch stdin (fd 0) to see when it has input. */
		FD_ZERO(&rfds);
		FD_SET(0, &rfds);

		/* Wait up to five seconds. */
		tv.tv_sec = 5;
		tv.tv_usec = 0;

		retval = select(1, &rfds, NULL, NULL, &tv);
		/* Don't rely on the value of tv now! */

		if (retval == -1) {
			if (errno == EINTR) {
				continue;
			}

			perror("select()");
			continue;
		}

		if (retval == 0) {
			/* fprintf(stderr, "Timeout reached.\n"); */
			continue;
		}

		if (!FD_ISSET(0, &rfds)) {
			fprintf(stderr, "BUG: Empty read-set, this should"
				" never happen. Never ever. Really! :-)\n");
			continue;
		}

		len = read(0, buf, sizeof(buf) - 1);
		if (len < 0) {
			perror("read()");
			continue;
		}

		buf[len] = 0;
		printf("%s", buf);

		if (len == 0) {
			do_quit = 1;
		}
	}

	return 1;
}
