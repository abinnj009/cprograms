#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *thread_st;

//fn executed by the kernel thread
static int thread_fn(void *unused)
{
	while(!thread_should_stop())
	{
		printk(KERN_INFO "Thread Running\n");
		ssleep(5);
	}
	printk(KERN_INFO "thread stopping\n");
	do_exit(0);
	return 0;
}
//module initialization
static int __init init_thread(void)
{
	printk(KERN_INFO "Creating thread\n");
	//create the kernel thread with name 'mythread'
	thread_st = kthread_run(thread_fn, NULL, "mythread");
	if(thread_st)
		printk(KERN_INFO "thread created succesfully");
	else
		printk(KERN_ERR "thread creation failed");
	return 0;
}

//module exit
static void __exit cleanup_thread(void)
{
	printk(KERN_INFO "cleaning up\n");
	if(thread_st)
	{
		kthread_stop(thread_st);
		printk(KERN_INFO "THREAD stopped");
	}
}
module_init(init_thread);
module_exit(cleanup_thread);
