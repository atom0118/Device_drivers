#include"headers.h"

static int num = 5;
//module_param(num,int,S_IUGO);
module_param(num,int,0660);

static char *name = "Atul";
module_param(name,charp,0660);

static int __init init_func(void)
{
	int i;
	for( i=0; i<num; i++) 
	{
		printk(KERN_INFO "%s\n", name);
	}
	return 0;
}

static void __exit exit_func(void)
{
	printk(KERN_ALERT "Module removed successfully\n");

}


module_init(init_func);
module_exit(exit_func);
