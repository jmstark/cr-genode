REQUIRES       = odroid_u3
FIASCO_DIR    := $(call select_from_ports,focnados)/src/kernel/foc/kernel/fiasco
KERNEL_CONFIG  = $(REP_DIR)/config/odroid_u3.kernel

-include $(PRG_DIR)/../../target.inc
