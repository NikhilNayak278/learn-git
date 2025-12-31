#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

void* print(void *row_num) {
    int row = (int)row_num;  // Simple cast from void*
    int sum = 0;
    int m;
    
    printf("Hi I am thread %d\n", row);
    for(m = 0; m < 3; m++) {
        sum += a[row][m];
    }
    printf("sum of row %d is %d\n", row, sum);
    return NULL;
}

int main() {
    pthread_t tid[3];
    
    for(int i = 0; i < 3; i++) {
        pthread_create(&tid[i], NULL, print, (void *)(int)i);
        sleep(1);
    }
    
    for(int i = 0; i < 3; i++) {
        pthread_join(&tid[i], NULL);
        sleep(1);
    }
    return 0;
}

