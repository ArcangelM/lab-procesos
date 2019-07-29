#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
  int pid;
  char *args[] = {"/bin/ls", "-l", ".", NULL};

  if ((pid = fork()) == 0) {

  		//execl("/bin/ls", "/bin/ls", ".", NULL);
  		//execlp("/bin/ls", "/bin/ls", ".", NULL);
  		//execle("/bin/ls", "/bin/ls", ".", NULL);
  		//execv("/bin/ls", args);
  		//execvp("/bin/ls", args);


  }
  else {
    wait(&pid);
    printf("exec finalizado\n");
  }
  return 0;
}