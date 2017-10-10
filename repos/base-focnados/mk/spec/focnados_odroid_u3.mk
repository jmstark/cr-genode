SPECS += focnados_arm odroid_u3

include $(call select_from_repositories,mk/spec/odroid_u3.mk)
include $(call select_from_repositories,mk/spec/focnados_arm.mk)
