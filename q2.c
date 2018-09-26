/*--------------------------------------
# Dylan Ollikka
# Lab 2 Problem 02
# Lab section: X02L, Fall 2018
# CMPUT 360, Fall 2018
# Stephanie Husby
*-------------------------------------*/

/* In this question both the parent process and child process are able to access
  the file descriptor. However, when both write to the file, the parent process
  is not able to finish its writing as the child process starts execution
  and writes to the file. Once the child process writes to the file it is also
  interupted again when process switches to the parent.
  Overall, both processes are not able to finish their writing to the file and
  when processes switch execution it is interupted
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(void){

  FILE *fp;
  fp = fopen("q2.txt", "w");

  int rc = fork();

  if (rc<0){
    printf("Error in forking..\n");
    exit(1);
}
  //child process
  else if(rc==0){
    printf("Child processing\n");
    fwrite("child writing", 1, sizeof(fp), fp);

  }

  //parent process
  else{
    printf("Parent processing\n");
    fwrite("parent writing", 1, sizeof(fp), fp);
  }
fclose(fp);
return 0;
}
