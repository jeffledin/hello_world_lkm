obj-m+=helloWorld.o

all:
	make -C /lib/modules/4.9.32-v7+/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/4.9.32-v7+/build/ M=$(PWD) clean
