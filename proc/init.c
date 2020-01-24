#include"headers.h"
#include"declarations.h"

static __init int driver_init(void);
static __exit void driver_exit(void);

module_init(driver_init);
module_exit(driver_exit);

/* procfs file operations mapping */
struct file_operations proc_fops = { 
    .open = proc_open,
    .read = proc_read,
//  .write = proc_write,
//  .release = proc_release,
};


static __init int driver_init(void)
{
	#ifdef DEBUG
	printk(KERN_INFO "This is my driver module for testing proc entry\n");
	#endif

	/* creating proc entry by the name "atul" making proc as a parent folder */
	proc_create("atul",0664,NULL,&proc_fops);			// This is a macro and not a function so have not checked for the return value

	return 0;
}

static __exit void driver_exit(void)
{
	#ifdef DEBUG
	printk(KERN_INFO "Exiting proc test driver\n");
	#endif

	/* Removing proc entry */
	remove_proc_entry("atul",NULL);						// This is a macro, so not checking for the return value

}
