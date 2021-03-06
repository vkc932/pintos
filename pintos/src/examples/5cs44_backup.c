#include <stdio.h>
#include <./threads/thread.h>
#include <./threads/synch.h>
#include <random.h>

struct semaphore smoker1,smoker2,smoker3,agent;

enum{
	tobaco_match,
	match_paper,
	paper_tobaco	
};




void smoker1_fun(void *aux){
	while(1){
	sema_down(&smoker1);
	printf("I AM SMOKER 1\n");
	sema_up(&agent);
	}
}



void smoker2_fun(void *aux){
	
	
	
		while(1){
	sema_down(&smoker2);
	printf("I AM SMOKER 2\n");
	sema_up(&agent);
	}	

}


	
void smoker3_fun(void *aux){
	
		while(1){
	sema_down(&smoker3);
	printf("I AM SMOKER 3\n");
	sema_up(&agent);
	}
}

void agent_fun(void *aux){
		int i=0;
	while(i<5){
		sema_down(&agent);

		long num=random_ulong()%3;

		if (tobaco_match==num)
		{	
			
			sema_up(&smoker1);
		}else if(match_paper==num){
			
			sema_up(&smoker2);
		}else if(paper_tobaco){
		
			sema_up(&smoker3);
		}

		i++;

	}
	

}



void test_5cs44(void){

	random_init(99999);

	sema_init(&smoker1,0);
	sema_init(&smoker2,0);
	sema_init(&smoker3,0);
	sema_init(&agent,1);

	thread_create("thread1",PRI_DEFAULT,smoker1_fun,NULL);
	thread_create("thread2",PRI_DEFAULT,smoker2_fun,NULL);
	thread_create("thread3",PRI_DEFAULT,smoker3_fun,NULL);
	thread_create("thread4",PRI_DEFAULT,agent_fun,NULL);
	
}
