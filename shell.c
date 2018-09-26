/*--------------------------------------
# Dylan Ollikka
# Lab 2 Problem Shell
# Lab section: X02L, Fall 2018
# CMPUT 360, Fall 2018
# Stephanie Husby
*-------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int
main(void){

char *cmdline;
char *token = NULL;
int i, rc;
char *args[10];
// run_back is 0: no process to run in background, run_back is 1: run a process
// in the background
int run_back = 0;

// while loop to run until user enters "exit" command
while (1){
cmdline = calloc(1, 1024);
printf("Prompt>");
fgets(cmdline, 1024, stdin);
fprintf(stderr, "[debug] cmdline = *%s*\n", cmdline);
// reset array iterator to 0 each loop
i = 0;

token = strtok(cmdline, "\n");
while (token!=NULL){
  args[i++] = strdup(token);
  token = strtok(NULL, "\n");
}

args[i] = NULL;
free(cmdline);


// if user enters "exit" break out of loop, and terminate the program
if (strcmp(args[0], "exit")==0){
  break;
}

// if user enters an ampersand as the final character set the run_back variable
// to 1 to indicate we will run a process in the background later on
if (strcmp(args[i-1], "&")==0){
  run_back = 1;
}

// create our processes. If the fork is < 0 we exit, as there was an error in
// forking. If the fork is 0, it is a child process and we call execvp to create
// a new program which executes the commandline. Finally, if run_back variable is 1
// then we run a process in the background by calling wait()
rc = fork();

// fork failed
if (rc<0){
  printf("Error in forking..\n");
  exit(1);
}

//child process
else if(rc==0){
  execvp(args[0], args);
}

// parent process, run_back is 1 so run a process in the background
else if(!run_back){
  wait(NULL);
}
}

return 0;
}
