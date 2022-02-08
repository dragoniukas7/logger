#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <logger.h>
#include <stdbool.h>

static bool run = 1;

void bye(int sig){
	if (sig == SIGINT){
		printf("received SIGINT\n");
		printf("Closing logger\n");
		close_logger();
		run = 0;
	}
}

int main(int argc, char *argv[]){

	if(init_logger() != 0)
		return 1;
	
	signal(SIGINT, bye);

	while(run){
		add_log(argv[0], 6, "random text");
		printf("Logging..\n");
		sleep(1);
	}

	return 0;
}
