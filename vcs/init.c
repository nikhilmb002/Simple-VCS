#include "header.h"

void init(int argc, char **argv) {

	if(argc != 2) {
	
		printf("usage : vcs init\n");
		return;
	}

	struct stat st = {0};

	if(stat(VCS_DIR, &st) == -1) {
		
		 if(mkdir(VCS_DIR, 0755) == -1) {
		 
		 	perror("failed to create .vcs directory\n");
			exit(1);
		 }

		 FILE* fp = fopen(VCS_DIR "/" VCS_FILE, "w");
		 
		 if(fp == 0) {
		 
		 	printf("failed to create .vcs\n");
			exit(1);
		 }

		 fclose(fp);
		 printf("repository initialised\n");
	}

	else {
	
		printf("repository already exists\n");	
	}
}
