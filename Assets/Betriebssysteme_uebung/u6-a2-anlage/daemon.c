#include <stdio.h>
#include <signal.h>

#include "helpers.h"

void got_signal(int s) {
	/*
	 * For demonstration purposes only!
	 *
	 * In real-world applications avoid the execution of complex
	 * tasks in signal handlers, this cries for race conditions and
	 * exploits.
	 *
	 * https://web.archive.org/web/20070204064240/http://www.bindview.com:80/
	 % Services/Razor/Papers/2001/signals.cfm
	 */

	static int count = 2;

	fprintf(stderr, "Caught Ctrl-C, press %i more time%s to really"
		" quit.\n", count, count == 1 ? "" : "s");

	if (count-- > 1) {
		/* Catch subsequent SIGINTs */
		signal(SIGINT, got_signal);
	}
	else {
		/* Don't catch SIGINT anymore */
		signal(SIGINT, SIG_DFL);
	}
}

int main(void) {
	/*
	 * Initialization...
	 */
	void load_cfg(int x) // Wrapper um die inkompatibilität durch die fehlerhafte methodendeklaration zu beheben
	{
		load_config();
	}
	load_config();
	signal(SIGHUP, load_cfg); 
	signal(SIGINT, got_signal);
	signal(SIGKILL, SIG_IGN); // Unaufhaltsam, da SIGKILL sich ja eben genau nicht um das Programm kümmern soll, sondern einfach immer töten soll
	signal(SIGTERM, SIG_IGN); // Aufhaltbar
	
	/*
	 * Do some work.
	 */

	main_loop();

	return 0;
}
