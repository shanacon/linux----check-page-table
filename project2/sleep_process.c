#include<linux/init.h>
#include<linux/sched.h>
#include<linux/module.h>
#include<linux/wait.h>
#include<linux/time.h>
#include<linux/delay.h>
DECLARE_WAIT_QUEUE_HEAD(project2_queue_1);
DECLARE_WAIT_QUEUE_HEAD(project2_queue_2);
DECLARE_WAIT_QUEUE_HEAD(project2_queue_3);
bool flag = false;
asmlinkage int enter_wait_queue(int x){
    if(x == 1)
    	wait_event_interruptible(project2_queue_1,flag == true);
    else if(x == 2)
        wait_event_interruptible(project2_queue_2,flag == true);
    else if(x == 3)
        wait_event_interruptible(project2_queue_3,flag == true);
    printk("test\n");
    return 1;
}
