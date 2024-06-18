obj-m += Q3.o

# EXTRA_CFLAGS += -I/lib/modules/6.5.3-arch1-1/build/include/linux/ -I/lib/modules/6.5.3-arch1-1/build/include/linux/sched

all:
		make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
		
clean:
		make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

