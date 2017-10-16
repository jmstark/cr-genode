SPECS += cortex_a9 arm_v7a cadence_gem
REP_INC_DIR += include/spec/zybo
include $(call select_from_repositories,mk/spec/cortex_a9.mk)
