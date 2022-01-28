#include <setjmp.h>
#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

sigjmp_buf ctrlc_buf;

void handle_signals(int signo) {
  if (signo == SIGINT) {
    printf("You pressed Ctrl+C\n");
    siglongjmp(ctrlc_buf, 1);
  }
}

int main(int argc, char **argv)
{
   //printf("path is: %s\n", path_string);
  char * input;
  char * shell_prompt = "i-shell> ";
  if (signal(SIGINT, handle_signals) == SIG_ERR) {
    printf("failed to register interrupts with kernel\n");
  }

  //set up custom completer and associated data strucutres

  while (1) 
  {
    while ( sigsetjmp( ctrlc_buf, 1 ) != 0 );

    input = readline(shell_prompt);
    if (!input)
      break;
    add_history(input);

    //do something with the code

  }  
  return 0;
}
