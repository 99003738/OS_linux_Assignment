#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define max 1000

int ar[max];

void arrgen()
{
    int i=0;
    for(i=0;i<max;i++)
    {
        ar[i]=rand()%100;
    }
}
void* taskbodymax(void* pv)
{
	int i;
    int maximum_of_array=ar[0];
	for(i=1;i<1000;i++)
	{
		if(maximum_of_array < ar[i])
        {
            maximum_of_array=ar[i];
        }
	}
    printf("\nMaximum = %d",maximum_of_array);
	//pthread_exit(NULL);
}


int main()
{
    arrgen();
    int no_of_threads=10;
	pthread_t pt1[no_of_threads];	//thread handle
    for(int i=0;i<no_of_threads;i++)
    {
	    pthread_create(&pt1[i],NULL,taskbodymax,NULL);
        pthread_join(pt1[i],NULL);    
     }
	return 0;	//exit(0);
}