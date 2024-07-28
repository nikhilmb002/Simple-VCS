#include "header.h"

int main(int argc, char **argv) {

	if(argc < 2) {
	
		printf("usage\nvcs init \nvcs add filename\nvcs commit filename message\nvcs log\nvcs checkout filename version\n");

                exit(1);
	}

	int op = find_op(argv[1]);
	
	switch(op) {
	
		case 1  : init(argc, argv); break;

		case 2  : add(argc, argv); break;

		case 3  : commit(argc, argv); break;

		case 4  : checkout(argc, argv); break;

		case 5  : _log(argc, argv); break;

		default : printf("usage\nvcs init \nvcs add filename\nvcs commit filename message\nvcs log\nvcs checkout filename version\n"); 
			  
			  exit(1);
	}
}
