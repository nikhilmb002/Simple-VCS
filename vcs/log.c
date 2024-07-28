#include "header.h"

void _log(int argc, char **argv) {

	if(argc != 2) {

		printf("usage : vcs log\n");
		exit(1);
	}

	char f_loc[256];
	snprintf(f_loc, sizeof(f_loc), "%s/%s", VCS_DIR, VCS_FILE);

	FILE* fp = fopen(f_loc, "r");

	if(fp == 0) {

		printf("failed to open file\n");
		exit(1);
	}	

	char l[256];

	while(fgets(l, sizeof(l), fp)) {

		int v;
		sscanf(l, "%d", &v);

		if(v > 0) 		

			printf("%s", l);
	}

	fclose(fp);	
}
