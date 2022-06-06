#include <stdio.h> 
#include "files.h" 
#include "directory.h" 
#include "pipes.h" 

void main(int argc, char *argv[] )  {  
  
   	printf("Welcome to program: %s\n\n", argv[0]);  
   
   	if(argc < 3){ //./assgn type operation 
      printf("Please pass appropriate number of command line arguments for executing a function.\n");  
   	}  
   	else{  
   		//FILE
		if(strcmp(argv[1], "file")==0){
			if(strcmp(argv[2], "create")==0){
				createFile(argc,argv);
			}else if(strcmp(argv[2],"read")==0){
				readFile(argc,argv);
			}else if(strcmp(argv[2],"write")==0){
				writeFile(argc,argv);
			}else if(strcmp(argv[2],"open")==0){
				openAndCloseFile(argc,argv);
			}else if(strcmp(argv[2],"info")==0){
				infoFile(argc,argv);
			}else if(strcmp(argv[2],"chmod")==0){
				changeMode(argc,argv);
			}else{
				printf("Invalid command for regular files.\n");
			}
		}else if(strcmp(argv[1],"directory")==0){ //DIRECTORY
			if(strcmp(argv[2],"create")==0){
				createDirectory(argc,argv);
			}else if(strcmp(argv[2],"chmod")==0){
				changeMode(argc,argv);
			}else if(strcmp(argv[2],"info")==0){
				infoFile(argc,argv);
			}else{
				printf("Invalid command for directories.\n");
			}
		}else if(strcmp(argv[1],"pipe")==0){ //PIPE
			if(strcmp(argv[2],"named")==0){
				createNamedPipe(argc,argv);
			}else if(strcmp(argv[2],"unnamed")==0){
				createUnnamedPipe(argc,argv);
			}else{
				printf("Invalid command for directories.\n");	
			}
		}else{
			printf("Invalid argument. First argument must be a file, pipe or directory.\n");
		}
	}  
}  
