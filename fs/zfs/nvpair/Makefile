ifneq ($(KBUILD_EXTMOD),)
src = /home/markus/linux/zfs/module/nvpair
obj = /home/markus/linux/zfs/module/nvpair
endif

MODULE := znvpair

obj-$(CONFIG_ZFS) := $(MODULE).o

$(MODULE)-objs += nvpair.o
$(MODULE)-objs += fnvpair.o
$(MODULE)-objs += nvpair_alloc_spl.o
$(MODULE)-objs += nvpair_alloc_fixed.o
