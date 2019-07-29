#include <stdio.h>
#include <unistd.h>


int main (void){
 
  int x = 100;
  printf("Empezando proceso %d\n", getpid());  
  if(fork() == 0) {
     printf("Empezando proceso hijo  %d con x igual a %d\n", getpid(), x); 
  }
  printf("Finalizando proceso %d\n", getpid());
  return 0;
}
