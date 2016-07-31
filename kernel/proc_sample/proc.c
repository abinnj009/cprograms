#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>



static int my_proc_show(struct seq_file *m, void * v)
{
	seq_printf(m,"ebin:number of jiffies:%lu\n", jiffies );
	return 0;
}
static int my_proc_open(struct inode *inode, struct file *file) 
{
	return single_open(file, my_proc_show, NULL);
}
static struct file_operations my_proc_fops = {
	.owner = THIS_MODULE,
	.open = my_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};
static int __init proc_init(void) 
{
/* create proc entry method 1 */	
	struct proc_dir_entry *entry;
	entry = create_proc_entry("ebin", 0, NULL);
	if (entry)
		entry->proc_fops = &my_proc_fops;
/* create proc entry method 2 */
	proc_create("my_proc", 0, NULL, &my_proc_fops);
	return 0;
}
static void __exit proc_exit(void)
{
	remove_proc_entry("my_proc", NULL);
	remove_proc_entry("ebin", NULL);
}
module_init(proc_init);
module_exit(proc_exit);
	
