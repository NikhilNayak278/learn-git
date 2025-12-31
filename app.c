#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    printf("Sum=%d\n", sum);  // Add newline, move outside loop
    return 0;  // Add return
}

