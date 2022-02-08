#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <logger.h>
#include <unistd.h> 

int main(int argc, char *argv[])
{
	int option;
	char* program = NULL;	

	init_logger();
	
	while ((option = getopt(argc, argv, "P:")) != -1) {
		switch (option) {
		case 'P':
			program = optarg;
		break;
		default:
			printf("Unknown flag");
		}
	}
	
	if(program != NULL)
		print_log(program);
	else
		print_log(NULL);
	
	close_logger();
	
	return 0;
}
