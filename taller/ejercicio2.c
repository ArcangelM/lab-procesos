#include <stdio.h>
#include <error.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  int fd;
  int pid;
  char ch1, ch2;
  fd = open("data.txt", O_RDWR);
  write(fd, "como\n" , 5);
  pid = fork();
  if(pid < 0) {
    perror("fork fallo");
    exit(-1); //Sale con código de error
  }else if (pid == 0) {
    write(fd, "estas\n", 6);
  } else {
    sleep(1);
    write(fd, "tu\n", 3);
  }
  return 0;
}