// this is a dynamic program which takes an amount of arguments between 2 and 5 and executes them
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string.h>

int main(int argc, char **argv){
	if ((argc - 1) < 2 || (argc - 1) > 5) { // checking number of arguments
		perror("Invalid number of arguments. The maximum number of arguments should not exceed 5, and not be less than 2.\n");
		exit(1);
	}
		
	int inPipe[2];
	pipe(inPipe);
	
	int originalPPID = getppid();
	int childpid[argc];
	char split[argc][2];
	char *token;
	for(int i = 1; i < argc; i++) {
		char *temp = argv[i];
		token= strtok(argv[i], " ");
		int j = 0;
		while(token != NULL) {
			split[i][j] = *token;
			token = strtok(NULL, " ");
			j++;
		}
	}
	 
	for(int i = 1; i < argc; i++) {
		if ((childpid[i] = fork()) == -1) {
			perror("Error creating child process");
			exit(1);
		}
		if(getppid() != originalPPID){ // removing child processes not part of the original parent
			exit(1);
		}
		switch (i) {
			case 1:
				dup2(inPipe[1], 1); // replace first command's output with write end of pipe
				close(inPipe[0]);
				close(inPipe[1]);

				execvp(argv[i], argv+i);
				break;
			case 2:	
				dup2(inPipe[0], 0); // replace second command's stdin with read end of pipe
				if(argc > 3)
					dup2(inPipe[1], 1); // replace second command's output with write end of pipe
				close(inPipe[0]);
				close(inPipe[1]);
				execvp(argv[i], argv+i);
				break;
			case 3: 
				dup2(inPipe[0], 0); // replace third command's stdin with read end of pipe
				if(argc > 4)
					dup2(inPipe[1], 1); // replace third command's output with write end of pipe
				execvp(argv[i], argv+i);
				close(inPipe[0]);
				close(inPipe[1]);
				break;
			case 4:
				dup2(inPipe[0], 0); // replace fourth command's stdin with read end of pipe
				if(argc > 5)
					dup2(inPipe[1], 1); // replace fourth command's output with write end of pipe
				execvp(argv[i], argv+i);
				close(inPipe[0]);
				close(inPipe[1]);
				break;
			case 5:
				dup2(inPipe[0], 0); // replace fifth command's stdin with read end of pipe
				execvp(argv[i], argv+i);
				close(inPipe[0]);
				close(inPipe[1]);
				break;	
			default:
				break;
		}
		exit(0);
	}
	return(0);
}
