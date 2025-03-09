obj-m := gpio-sysfs.o
ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
KERN_DIR =/home/vm/Linux-DD-BBB/workspace/ldd/source/linux-5.4/
HOST_KERN_DIR = /lib/modules/$(shell uname -r)/build/

all:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) modules
clean:
	make -C $(KERN_DIR) M=$(PWD) clean
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) clean
	rm -rf *.o *.elf
help:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERN_DIR) M=$(PWD) help
host:
	make -C $(HOST_KERN_DIR) M=$(PWD) modules

copy-dtb: 
	scp /home/vm/Linux-DD-BBB/workspace/ldd/source/linux-5.4/arch/arm/boot/dts/am335x-boneblack.dtb root@192.168.31.252:/root/

copy-drv: 
	scp *.ko *.elf root@192.168.31.252:/root/

app: lcd_app.o lcd.o gpio.o lcd_app.elf

lcd_app.o: lcd_app.c
	$(CROSS_COMPILE)gcc -c -o $@ $^

lcd.o: lcd.c
	$(CROSS_COMPILE)gcc -c -o $@ $^

gpio.o: gpio.c
	$(CROSS_COMPILE)gcc -c -o $@ $^

lcd_app.elf: lcd_app.o lcd.o gpio.o
	$(CROSS_COMPILE)gcc -o $@ $^





