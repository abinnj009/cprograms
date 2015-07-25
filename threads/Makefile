ifneq (${KERNELRELEASE},)
	obj-m := thread.o
else
	KERNEL_SOURCE := /usr/src/linux-headers-4.2.0-rc3-custom
PWD := $(shell pwd)
default:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules
clean:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean
endif
