REQUIRES += arm
SRC_CC   += spec/arm/platform_arm.cc \
            spec/arm/ipc_pager.cc

# override default stack-area location
INC_DIR  += $(REP_DIR)/src/include/spec/arm

include $(REP_DIR)/src/core/target.inc

vpath platform_services.cc $(GEN_CORE_DIR)
