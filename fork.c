#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char * argv[]){
int id,wt;
id=fork();

if(id==0){
printf("Hi I am child , my pis is %d \n ",getpid());
printf("child: my parent pid is %d \n ",getppid());
execl("./app", "./app", argv[1], NULL);

exit(34);

}
else if(id>0){
wait(&wt);
printf("Hi I am parent , my pis is %d \n ",getpid());
}
if(WIFEXITED(wt)){

printf("this child is normally terminated and it exit status is %d \n", WEXITSTATUS(wt));
}
else{
printf("child teminated abnormally\n");

}
}
