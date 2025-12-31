#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define buffersize 10

pthread_mutex_t mutex;
pthread_t tidP[20],tidC[20];
sem_t full,empty;
int item_count;
int buffer[buffersize];

void initialize(){
pthread_mutex_init(&mutex,NULL);
sem_init(&full,0,0);
sem_init(&empty,0,buffersize);
item_count=0;

}

void write( int item){
buffer[item_count++]=item;
}

int read(){
return (buffer[--item_count]);
}

void* producer(void * param){
int item;
item=rand()%10;

sem_wait(&empty);
pthread_mutex_lock(&mutex);

printf("\n producer has produced item: %d\n",item);
write(item);

pthread_mutex_unlock(&mutex);
sem_post(&full);

}


void* consumer(void * param){
int item;
sem_wait(&full);

pthread_mutex_lock(&mutex);

item=read();
printf("\n consumer has consumed item:%d \n",item);

pthread_mutex_unlock(&mutex);
sem_post(&empty);





}

int main(){
int n1,n2,i;

initialize();

printf("\n enter the number of producer :");
scanf("%d",&n1);
printf("\n enter the number of consumer :");
scanf("%d",&n2);

for(i=0;i<n1;i++){
pthread_create(&tidP[i],NULL,producer,NULL);
}

for(i=0;i<n2;i++){
pthread_create(&tidC[i],NULL,consumer,NULL);
}

for(i=0;i<n1;i++){
pthread_join(&tidP[i],NULL);
}

for(i=0;i<n2;i++){
pthread_join(&tidC[i],NULL);
}

exit(0);

}
