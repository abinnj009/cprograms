#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/kthread.h>
static struct task_struct *thread_st;

static int thread_fn(void *unused)
{
	while (1)
	{
		printk(KERN_INFO "Thread Running now!\n");
		ssleep(5);
	}
	printk(KERN_INFO "Thread stopped now\n");
	do_exit(0);
	return 0;
}

static int __init init_thread(void)
{
	printk(KERN_INFO "Creating Thread\n");
	//create the kernel thread with name mythread
	thread_st = kthread_create(thread_fn, NULL, "mythread");
	if (thread_st)
		printk(KERN_INFO "Thread created succesfully\n");
	else
		printk(KERN_INFO "Thread creation failed\n");
	return 0;
}

static void __exit cleanup_thread(void)
{
	printk(KERN_INFO "cleaning up\n");
}

module_init(init_thread);
module_exit(cleanup_thread);

