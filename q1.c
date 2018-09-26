/*--------------------------------------
# Dylan Ollikka
# Lab 2 Problem 01
# Lab section: X02L, Fall 2018
# CMPUT 360, Fall 2018
# Stephanie Husby
*-------------------------------------*/

/* For this question, changing the value of a variable (x) works as expected.
  This works this way since when a process is made, it works on the variable
  individually by itself, and does not use any value changed from another
  process
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(void){

  int x = 1000;
  printf("Initially, the value for x is: %d\n",x);
  int rc = fork();

  //fork error
  if (rc<0){
    printf("Error in fork, returning....\n");
    exit(1);
  }

  //process the child
  else if (rc==0){
    //change value for x in child processing
    x+=2000;
    printf("\nAfter the CHILD process, X + 2000= %d\n", x);
  }

  //process the parent
  else{
    //change value for x in parent processing
    x+=3000;
    printf("\nAfter the PARENT process, X + 3000= %d\n", x);
  }

return 0;
}
