#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("%d: code before forking - executed once only\n", getpid());

  fork();

  printf("%d: code after forking - executed by each process\n", getpid());
}
