#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/kdev_t.h>
#include<linux/uaccess.h>
#include <linux/platform_device.h>
#include<linux/slab.h>
#include<linux/mod_devicetable.h>



#undef pr_fmt
#define pr_fmt(fmt) "%s : " fmt,__func__


/*platform data of the pcdev */
struct pcdev_platform_data
{
	int size;
	int perm;
	const char *serial_number;

};

/*Permission codes */

#define RDWR 0x11
#define RDONLY 0x01
#define WRONLY 0x10

/*Device private data structure */
struct pcdev_private_data
{
	struct pcdev_platform_data pdata;
	char *buffer;
	dev_t dev_num;
	struct cdev cdev;
};


/*Driver private data structure */
struct pcdrv_private_data
{
	int total_devices;
	dev_t device_num_base;
	struct class *class_pcd;
	struct device *device_pcd;
};


/*Driver's private data */
struct pcdrv_private_data pcdrv_data;

int check_permission(int dev_perm, int acc_mode)
{

    return 0;

}


loff_t pcd_lseek(struct file *filp, loff_t offset, int whence)
{

	 return filp->f_pos;
    
}

ssize_t pcd_read(struct file *filp, char __user *buff, size_t count, loff_t *f_pos)
{   return 0;
}

ssize_t pcd_write(struct file *filp, const char __user *buff, size_t count, loff_t *f_pos)
{
	
    return 0;
}



int pcd_open(struct inode *inode, struct file *filp)
{

	int ret;

	
	return 0;
}

int pcd_release(struct inode *inode, struct file *flip)
{
	pr_info("release was successful\n");

	return 0;
}


/* file operations of the driver */
struct file_operations pcd_fops=
{
	.open = pcd_open,
	.release = pcd_release,
	.read = pcd_read,
	.write = pcd_write,
	.llseek = pcd_lseek,
	.owner = THIS_MODULE
};



/*Called when the device is removed from the system */
int pcd_platform_driver_remove(struct platform_device *pdev)
{
	pr_info("A device is removed\n");

	return 0;
}

/*Called when matched platform device is found */
int pcd_platform_driver_probe(struct platform_device *pdev)
{
	int ret;

	struct pcdev_private_data *dev_data;

	struct pcdev_platform_data *pdata;

	pr_info("A device is detected\n");

    pr_info("Probe was successful\n");

	return 0;

}



struct platform_driver pcd_platform_driver = 
{
	.probe = pcd_platform_driver_probe,
	.remove = pcd_platform_driver_remove,
	.driver = {
		.name = "Platform-Driver"
	}

};



static int __init pcd_platform_driver_init(void)
{
	int ret;
	
	/*Register a platform driver */
	platform_driver_register(&pcd_platform_driver);
	
	pr_info("mypcd platform driver loaded\n");
	
	return 0;

}

static void __exit pcd_platform_driver_cleanup(void)
{
	pr_info("pcd platform driver unloaded\n");
	platform_driver_unregister(&pcd_platform_driver);

}



module_init(pcd_platform_driver_init);
module_exit(pcd_platform_driver_cleanup);

//module_platform_driver(pcd_platform_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ibrahim Pasha");
MODULE_DESCRIPTION("A pseudo character platform driver which handles n platform pcdevs");