#include<linux/module.h>
#include<linux/platform_device.h>


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


struct pcdev_platform_data pcdev_pdata[] ={
    [0] = {.size = 512, .perm = RDWR,   .serial_number = "PCDEVA"},
	[1] = {.size = 1024,.perm = RDWR,   .serial_number = "PCDEVB"},
    [2] = {.size = 512, .perm = RDONLY,   .serial_number = "PCDEVC"},
	[3] = {.size = 1024,.perm = WRONLY,   .serial_number = "PCDEVD"}
};


void pcdev_release (struct device *dev)
{
    struct pcdev_platform_data *pdev = (struct pcdev_platform_data*)dev->platform_data;
    
    pr_info("Device : %s released \n",pdev->serial_number);
}




struct platform_device platform_pcdev_1={
    .name = "Platform-Driver",
    .id = 0,
    .dev = {
		.platform_data = &pcdev_pdata[0],
		.release = pcdev_release
	}

};
struct platform_device platform_pcdev_2 = {
    .name = "Platform-Driver",
    .id = 1,
    .dev = {
		.platform_data = &pcdev_pdata[1],
		.release = pcdev_release
	}

};

struct platform_device platform_pcdev_3 = {
    .name = "Platform-Driver",
    .id = 2,
    .dev = {
		.platform_data = &pcdev_pdata[2],
		.release = pcdev_release
	}

};

struct platform_device platform_pcdev_4 = {
    .name = "Platform-Driver",
    .id = 3,
    .dev = {
		.platform_data = &pcdev_pdata[3],
		.release = pcdev_release
	}

};

struct platform_device *platform_pcdevs[] = 
{
	&platform_pcdev_1,
	&platform_pcdev_2,
	&platform_pcdev_3,
	&platform_pcdev_4
};



static int __init pcdev_platform_init(void)
{
	/* register n platform devices */

	platform_device_register(&platform_pcdev_1);
	platform_device_register(&platform_pcdev_2);
	platform_device_register(&platform_pcdev_3);
	platform_device_register(&platform_pcdev_4);
	

//    platform_add_devices(platform_pcdevs,ARRAY_SIZE(platform_pcdevs) );

	pr_info("Device setup module loaded \n");

	return 0;
}


static void __exit pcdev_platform_exit(void)
{

	platform_device_unregister(&platform_pcdev_1);
	platform_device_unregister(&platform_pcdev_2);
	platform_device_unregister(&platform_pcdev_3);
	platform_device_unregister(&platform_pcdev_4);
	

	pr_info("Device setup module unloaded \n");


}

module_init(pcdev_platform_init);
module_exit(pcdev_platform_exit);


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module which registers n platform devices ");
MODULE_AUTHOR("Ibrahim Pasha");


