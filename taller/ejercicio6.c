#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;
	int status;
	if ((pid = fork()) < 0) {
		perror("fork falló");
		exit(-1);

	} else if (pid == 0) {
		printf("Hola soy el hijo\n");

	} else {
        waitpid(pid, &pid, WUNTRACED);
		printf("Hola soy el padre\n");

	}
}

