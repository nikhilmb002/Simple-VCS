#include "header.h"

void add(int argc, char** argv) {

	if(argc != 3) {
	
		printf("usage : vcs add filename\n");
		return;
	}

	if(access(argv[2], F_OK) == -1) {
	
		perror("file doesn't exist");
		exit(1);
	}

	char file_loc[256];
	snprintf(file_loc, sizeof(file_loc), "%s/%s", VCS_DIR, VCS_FILE);

	FILE* fp = fopen(file_loc, "a+");

	if(fp == 0) {
	
		perror("failed to open file");
		exit(1);
	}

	char l[256];

	while(fgets(l, sizeof(l), fp)) {
		
		char t_file[128];
		sscanf(l, "%*d %s %*s", t_file);

		if(strcmp(t_file, argv[2]) == 0) {
			
			printf("file %s already tracking\n", argv[2]);
			fclose(fp);
			return;
		}
	}
	
	fprintf(fp, "0 %s\n", argv[2]);
	fclose(fp);

	printf("file %s added to vcs\n", argv[2]);
}

















