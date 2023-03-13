#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  int pid;

  pid = fork();

  if (pid == 0) 
  { // child proc looping endlessly
    printf("%d: child ...\n", getpid());
    for(;10;);
  } 
  else 
  { // parent proc
    printf("%d: parent; child pid: %d \n", getpid(), pid);
    wait(NULL); // for child termination
    printf("%d: parent after wait ... terminating\n", getpid());
  }
}
