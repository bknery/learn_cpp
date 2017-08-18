#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>

static void read_file(char *filename)
{
  int fd;
  char buf[1];

  mm_segment_t old_fs = get_fs();
  set_fs(KERNEL_DS);

  fd = sys_open(filename, O_RDONLY, 0);
  if (fd >= 0) {
    printk(KERN_DEBUG);
    while (sys_read(fd, buf, 1) == 1)
      printk("%c", buf[0]);
    printk("\n");
    sys_close(fd);
  }
  set_fs(old_fs);
}

static int __init read_user_space_init(void)
{
  printk(KERN_INFO "Opening kernel module read from user space\n");
  read_file("/etc/shadow");
  return 0;
}

static void __exit read_user_space_exit(void)
{
    printk(KERN_INFO "Closing kernel module read from user space\n");
}

MODULE_LICENSE("GPL");
module_init(read_user_space_init);
module_exit(read_user_space_exit);
