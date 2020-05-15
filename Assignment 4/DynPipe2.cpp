#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void read_all(int src, int dst) {
	char buf[BUFSIZ];
	ssize_t bytes_read, bytes_written;
	while ((bytes_read = read(src,buf,BUFSIZ)) > 0) {
		bytes_written = 0;
		while(bytes_written < bytes_read)
			bytes_written += write(dst, buf + bytes_written, bytes_read - bytes_written);
	}
}

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Arguments need to be between 2 and 5");	
		return EXIT_FAILURE;	
	}
	int inPipe[2];
	int outPipe[2];
	int errPipe[2];
	pipe(inPipe);
	pipe(outPipe);
	pipe(errPipe);

	if(fork() == 0) {
		close(inPipe[1]);
		close(outPipe[0]);
		close(errPipe[0]);

		dup2(inPipe[0], STDIN_FILENO);
		dup2(outPipe[1], STDOUT_FILENO);
		dup2(errPipe[1], STDERR_FILENO);

		if (execvp(argv[1], argv+1) == -1) {
			perror("failed to start subprocess");
			return EXIT_FAILURE;
		}
	}
	close(inPipe[0]);
	close(outPipe[1]);
	close(errPipe[1]);

	read_all(STDIN_FILENO, inPipe[1]);
	close(inPipe[1]);
	wait(NULL);
	puts("\nchild's stdout:");
	fflush(stdout);
	read_all(outPipe[0], STDOUT_FILENO);
	close(outPipe[0]);
	puts("\nchild's stderr:");
	read_all(errPipe[0], STDOUT_FILENO);
	close(errPipe[0]);
	return EXIT_SUCCESS;
	
	

}
