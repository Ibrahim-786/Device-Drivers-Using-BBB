obj-m := pcd_sysfs.o
pcd_sysfs-objs += pcd_platform_driver_dt_sysfs.o pcd_syscalls.o
ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
KERN_DIR = /home/vm/Linux-DD-BBB/workspace/ldd/source/linux-5.4/
HOST_KERN_DIR = /lib/modules/$(shell uname -r)/build/

all:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) modules
clean:
	make -C $(HOST_KERN_DIR) M=$(PWD) clean
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) clean
help:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) help
host:
	make -C $(HOST_KERN_DIR) M=$(PWD) modules
copy-dtb:
	scp /home/vm/Linux-DD-BBB/workspace/ldd/source/linux-5.4/arch/arm/boot/dts/am335x-boneblack.dtb debian@192.168.31.253:/home/debian/drivers

copy-drv:
	scp *.ko  debian@192.168.31.253:/home/debian/drivers

