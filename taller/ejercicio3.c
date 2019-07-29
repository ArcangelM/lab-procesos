#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	pid_t pid;
	if ((pid = fork()) < 0) {
		perror("fork falló");
		exit(-1);

	} else if (pid == 0) {
		printf("Hello\n");

	} else {
        sleep(1);
		printf("goodbye\n");
	}
}

