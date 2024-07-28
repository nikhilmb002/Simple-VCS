#include "header.h"

int find_op(char *argv) {

	int choice;

	if(strcmp(argv, "init") == 0)

		choice = 1;

	else if(strcmp(argv, "add") == 0)

		choice = 2;

	else if(strcmp(argv, "commit") == 0)

		choice = 3;

	else if(strcmp(argv, "checkout") == 0)

		choice = 4;

	else if(strcmp(argv, "log") == 0)

		choice = 5;

	return choice;	
}
