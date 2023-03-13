#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  if (fork() == 0)
  { // child proc
    printf("%d: child created by parent %d; executing 'p4'...\n", getpid(), getppid());
    execl("p4", "p4", NULL);
  }
  else
  { // parent proc
    printf("%d: parent process\n", getpid());
  }

  fork();
  printf("%d: terminating\n", getpid());

  wait(NULL);
}
