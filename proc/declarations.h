#define DEBUG

int proc_open(struct inode *, struct file *);
ssize_t proc_read(struct file *, char __user *, size_t ,loff_t *);
 
