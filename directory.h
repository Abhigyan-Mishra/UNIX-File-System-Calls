#include <stdio.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>

mode_t to_Mode(char *perm){
	//Create string permission to mode_t
	mode_t mode = 0;
	if (perm[0] == 'r')
	    mode |= 0400;
	if (perm[1] == 'w')
	    mode |= 0200;
	if (perm[2] == 'x')
	    mode |= 0100;
	if (perm[3] == 'r')
	    mode |= 0040;
	if (perm[4] == 'w')
	    mode |= 0020;
	if (perm[5] == 'x')
	    mode |= 0010;
	if (perm[6] == 'r')
	    mode |= 0004;
	if (perm[7] == 'w')
	    mode |= 0002;
	if (perm[8] == 'x')
		mode |= 0001;
	return mode;
}


void createDirectory(int argc, char *argv[]){
	//./assgn directory create folder rwxrwxrwx
	mode_t old_mask = umask(0);
	if(argc!=5){
		printf("Invalid number of arguments.");
	}else{
		//Check if directory already exists
		struct stat st;
		if (stat(argv[3], &st)!=-1){
		    printf("Directory already exists");
		    return;
		}
		mode_t mode=to_Mode(argv[4]);
		//Create new directory
		int dir=mkdir(argv[3],mode);
		if(dir==-1){
			printf("Error while creating directory. \n");
		}else{
			printf("Directory created successfully. \n");	
		}
	}
	umask(old_mask);
}


