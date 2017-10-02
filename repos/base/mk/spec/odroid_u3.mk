# denote specs that are fullfilled by this spec
SPECS += exynos exynos4 cortex_a9 usb framebuffer gpio

# add repository relative paths
REP_INC_DIR += include/spec/odroid_u3
REP_INC_DIR += include/spec/exynos4
REP_INC_DIR += include/spec/exynos

# include implied specs
include $(call select_from_repositories,mk/spec/cortex_a9.mk)
