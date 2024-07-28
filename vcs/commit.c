#include "header.h"

void commit(int argc, char** argv) {

	if(argc != 4) {
	
		printf("usage vcs commit filename\n");
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

	int v = 0;
	char l[256];

	while(fgets(l, sizeof(l), fp)) {
	
		char t_file[128];
		sscanf(l, "%d %s %*s", &v, t_file);

		if(strcmp(t_file, argv[2]) == 0) {
			
			v++;
		}
	}

	char backup_loc[256];
	snprintf(backup_loc, sizeof(backup_loc), "%s/%s.%d", VCS_DIR, argv[2], v);
	
	FILE* src = fopen(argv[2], "r");
	FILE* dst = fopen(backup_loc, "w");

	if(src == 0 || dst == 0) {
	
		perror("failed to open copy files");
		exit(1);
	}

	char buffer[1024];
	size_t bytes;

	while((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
	
		fwrite(buffer, 1, bytes, dst);
	}

	fclose(src);
	fclose(dst);
	fprintf(fp, "%d %s %s\n", v, argv[2], argv[3]);
	fclose(fp);

	printf("changes saved as %d version", v);

}
