obj-m += user_helper.o

#KERNEL=/home/pi/linux
KERNEL=/lib/modules/`uname -r`/build



all:
	make -C $(KERNEL) M=$(shell pwd) modules 
clean:
	make -C $(KERNEL) M=$(shell pwd) clean
