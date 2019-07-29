#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>


int main () {
    int pipe_fds[2],
        pipe_ret;
    pid_t cpid, cpid2;

    
    pipe_ret = pipe(pipe_fds);

    if (pipe_ret == -1) {
        perror("Pipe Creation");
        exit(EXIT_FAILURE);
        }

    cpid = fork();

    if (cpid < 0) {
        perror("During attempted fork");
        exit(EXIT_FAILURE);
        }

    if (cpid == 0) {
        close(pipe_fds[0]);
        dprintf(pipe_fds[1], "Hermano, soy el hijo 1.\n");
        close(pipe_fds[1]);
        exit(EXIT_SUCCESS);
        }

     else if (cpid > 0) {

        cpid2 = fork();

        if (cpid2 < 0) {
            perror("falló el fork");
            exit(EXIT_FAILURE);
        }

        if (cpid2 == 0) {

            waitpid(cpid, &cpid, 0);
            close(pipe_fds[1]);

            int bytes_leer;
            char buf[256];

            while ((bytes_leer = read(pipe_fds[0], buf, 256 - 1)) > 0) {
                buf[bytes_leer] = '\0';
                printf("%s", buf);
            }

            close(pipe_fds[0]);

        }else if (cpid2 > 0) {

            printf("Soy el padre de ambos procesos.\n");
        }

     return 0;
     }
 }