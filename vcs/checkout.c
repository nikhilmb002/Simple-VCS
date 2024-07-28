#include "header.h"

void checkout(int argc, char **argv) {

	if(argc != 4) {
	
		printf("usage vcs checkout filename version\n");
		return;
	}

	char backup_loc[256];
	snprintf(backup_loc, sizeof(backup_loc), "%s/%s.%d", VCS_DIR, argv[2], atoi(argv[3]));

	if(access(backup_loc, F_OK) == -1) {
	
		perror("specified version doesn't exist");
		exit(1);
	}

	FILE *src = fopen(backup_loc, "r");
	FILE *dst = fopen(argv[2], "w");

	if(src == 0 || dst == 0) {
	
		perror("failed to open copy files");
		return;
	}

	char buffer[1024];
	size_t bytes;

	while((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
		
		fwrite(buffer, 1, bytes, dst);
	}

	fclose(src);
	fclose(dst);

	printf("reverted to version %d\n", atoi(argv[3]));

}
