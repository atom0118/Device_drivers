#include<linux/module.h>
#include<linux/init.h>
#include<linux/types.h>
#include<linux/kdev_t.h>		// For MAJOR and MINOR
#include<linux/fs.h>			// For "alloc_chrdev_region()"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Atul Pant");
MODULE_DESCRIPTION("Simple char driver to register major and minor number");

dev_t dev_num;

static int __init entry(void)
{
	printk(KERN_INFO "Driver inserted successfully\n");

	/* Allocating major number and minor number dynamically for our driver */
	if ( alloc_chrdev_region(&dev_num,0,2,"atul") !=0 ) {
		printk(KERN_ALERT "Cannot obtain major and minor num for device\n");
		return -1;
	}
	printk(KERN_INFO "MAJOR NUM: %d\n", MAJOR(dev_num) );
	printk(KERN_INFO "MINOR NUM: %d\n", MINOR(dev_num) );

	return 0;

}

static void __exit driver_exit(void)
{
	/* unregistering or giving back the major number and minor numbers to the kernel */
	unregister_chrdev_region(dev_num, 2);
	printk(KERN_INFO "Driver removed successfully\n");
}


module_init(entry);
module_exit(driver_exit);
