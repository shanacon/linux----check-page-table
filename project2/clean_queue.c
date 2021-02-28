#include <stdio.h>
#include <syscall.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("\n");
    int queue_number,ret;queue_number=2;
	printf("enter the queue_number you want release\n");
	scanf("%d",&queue_number);
	ret = syscall(360,queue_number);
	if(ret){
	    printf("clean queue:%d",queue_number);
	}
	else{
		printf("something wrong in clean_wait_queue!\n");
	}
    printf("exit\n");
    return 0;
}