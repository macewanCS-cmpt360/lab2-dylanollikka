/*--------------------------------------
# Dylan Ollikka
# Lab 2 Problem 07
# Lab section: X02L, Fall 2018
# CMPUT 360, Fall 2018
# Stephanie Husby
*-------------------------------------*/

/* For this question when child process uses close on STDOUT_FILENO it
  does not print anything when executing its process. Even when printf is called
  after, only the parent process executes its printf statements
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(void){

int rc = fork();

if (rc<0){
  printf("Error in forking..\n");
  exit(1);
}

//child process
else if(rc==0){
  printf("\nChild processing before closing standard output");
  close(STDOUT_FILENO);
  printf("Child process attempt at printing after STDOUT..\n");

}

//parent process
else{
  printf("\nParent processing");
}


return 0;
}
