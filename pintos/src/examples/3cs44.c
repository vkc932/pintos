#include <stdio.h>
#include <./threads/thread.h>


void print1(void *aux){
	printf("This is thread 1\n");

}



void print2(void *aux){
	printf("This is thread 2\n");

}



void print3(void *aux){
	printf("This is thread 3\n");

}



void print4(void *aux){
	printf("This is thread 4\n");

}



void print5(void *aux){
	printf("This is thread 5\n");

}

void test_3cs44(void){

	thread_create("thread1",1,print1,NULL);
	thread_create("thread2",2,print2,NULL);
	thread_create("thread3",3,print3,NULL);
	thread_create("thread4",5,print4,NULL);
	thread_create("thread5",4,print5,NULL);
}
