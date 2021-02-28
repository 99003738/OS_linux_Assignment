#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
sem_t s1;
sem_t s2;
int stack[100],top=-1;

void pop();
void push();

void* tentry_fun1(void* pv)	//pull
{
	int i;
	printf("A--welcome\n");
	sem_wait(&s2);
	sem_wait(&s1);

	pop();

	sem_post(&s1);
	//pthread_exit(NULL);
}


void* tentry_fun2(void* pv)	//push
{
	int i;
	printf("B--welcome\n");
	sem_wait(&s1);
	
	push();

	sem_post(&s1);
	sem_post(&s2);
	//pthread_exit(NULL);
}

int main()
{

	pthread_t pt1,pt2;
	sem_init(&s1,0,1);
	sem_init(&s2,0,0);	//thread handle

	pthread_create(&pt1,NULL,tentry_fun1,NULL);
	pthread_create(&pt2,NULL,tentry_fun2,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	sem_destroy(&s1);
	return 0;	//exit(0);
}

void push()
{
	top++;
        printf("pushed element is 50\n");
        stack[top]=50;
}
void pop()
{
	printf("popped elements is %d\n",stack[top]);
        top--;
}