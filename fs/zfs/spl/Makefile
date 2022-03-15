ifneq ($(KBUILD_EXTMOD),)
src = /home/markus/linux/zfs/module/spl
obj = /home/markus/linux/zfs/module/spl
mfdir = $(obj)
else
mfdir = $(srctree)/$(src)
endif

MODULE := spl

obj-$(CONFIG_ZFS) := $(MODULE).o

include $(mfdir)/../os/linux/spl/Makefile
