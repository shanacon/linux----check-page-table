#include <stdio.h>
#include <syscall.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main()
{

    srand(time(NULL));
    int queue_number,ret;
    pid_t ttid = syscall(224);//get ttid
    queue_number = (rand()%3)+1; 
    printf("\n  ttid :%d enter queue %d\n",ttid,queue_number);
    ret = syscall(359,queue_number);
    if(ret)
    	printf("ttid :%d release queue %d\n",ttid,queue_number);
    else
	    printf("something wrong in enter_wait_queue!\n");


    return 0;
}