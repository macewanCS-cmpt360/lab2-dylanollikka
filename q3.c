/*--------------------------------------
# Dylan Ollikka
# Lab 2 Problem 03
# Lab section: X02L, Fall 2018
# CMPUT 360, Fall 2018
# Stephanie Husby
*-------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int
main(void){

int rc = vfork();

if (rc<0){
  printf("Error in forking..\n");
  exit(1);
}

//child process
else if (rc==0){
  printf("\nHello! This is a child process");
}

//parent process
else{
  //int wc = wait(NULL);
  printf("\n Goodbye! Parent process finishing");
  exit(1);
}


return 0;
}
