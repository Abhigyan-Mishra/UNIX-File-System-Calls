#include <stdio.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void createUnnamedPipe(int argc, char *argv[]){
	//./assgn pipe unnamed text
	if(argc!=4){
		printf("\nInvalid number of arguments.");
		return;
	}
	int fd[2], nbytes;
	pid_t childpid;
	char buffer[128];
	
	//Create unnamed pipe
	int p=pipe(fd);
	if(p<0){
		printf("\nError in creating named pipe.");
		return;
	}
	//Call fork
	if((childpid = fork()) == -1) {
		perror("fork");
		exit(1);
	} 
	//if child process then write into pipe
	if(childpid == 0) {
		//close reading end
		close(fd[0]);
		//Write into pipe from buffer
		nbytes = write(fd[1], argv[3], (strlen(argv[3]) + 1));
		printf("\nBytes written by child process into pipe: %d \n",nbytes);
		exit(0);
	}else {//If parent process then read from child process
		//Close wriring end
		close(fd[1]);
		//Read from pipe into buffer
		nbytes = read(fd[0], buffer, sizeof(buffer));
		printf("\nBytes read by parent process from pipe: %d \n",nbytes);
		printf("\n\nData read by parent process: %s",buffer);
	}
}

void createNamedPipe(int argc, char *argv[]){
	//./assgn pipe named pipename
	if(argc!=4){
		printf("\nInvalid number of arguments.");
		return;
	}
    //Create named pipe
    int result = mknod (argv[3], S_IRUSR| S_IWUSR|S_IFIFO, 0);
	if (result < 0) {
	    printf("\nError in creating named pipe.");
	    exit (2);
	}else{
		printf("\nNamed pipe created successfully.");
	}
}


