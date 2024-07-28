#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define VCS_DIR ".vcs"
#define VCS_FILE "vcs_file.txt"

int find_op(char*);
void init(int, char**);
void add(int, char**);
void commit(int, char**);
void checkout(int, char**);
void _log(int, char**);
