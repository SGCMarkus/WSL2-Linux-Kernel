ifneq ($(KBUILD_EXTMOD),)
src = /home/markus/linux/zfs/module/unicode
obj = /home/markus/linux/zfs/module/unicode
endif

MODULE := zunicode

obj-$(CONFIG_ZFS) := $(MODULE).o

$(MODULE)-objs += u8_textprep.o
$(MODULE)-objs += uconv.o
