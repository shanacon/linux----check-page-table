#include<linux/init.h>
#include<linux/sched.h>
#include<linux/module.h>
#include<linux/wait.h>
#include<linux/time.h>
#include<linux/delay.h>
extern bool flag1;
extern bool flag2;
extern bool flag3;
extern wait_queue_head_t project2_queue_1;
extern wait_queue_head_t project2_queue_2;
extern wait_queue_head_t project2_queue_3;
asmlinkage int clean_wait_queue(int x){
    if(x == 1){
    	flag1 = true;
        wake_up_interruptible_all(&project2_queue_1);
    }
    else if(x == 2){
    	flag2 = true;
        wake_up_interruptible_all(&project2_queue_2);
    }
    else if(x == 3){
    	flag3 = true;
        wake_up_interruptible_all(&project2_queue_3);
    }
    printk("test4%d\n",flag1);
    printk("test5%d\n",flag2);
    printk("test6%d\n",flag3);
    return 1;
}
