obj-m := pcd_platform_driver_dt.o
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
	scp /home/vm/Linux-DD-BBB/workspace/ldd/source/linux-5.4/arch/arm/boot/dts/am335x-boneblack.dtb root@192.168.31.252:/root/


copy-drv:
	scp *.ko  root@192.168.31.252:/root/

