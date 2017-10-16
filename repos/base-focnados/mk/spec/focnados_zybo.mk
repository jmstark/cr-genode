SPECS += focnados_arm zybo

include $(call select_from_repositories,mk/spec/zybo.mk)
include $(call select_from_repositories,mk/spec/focnados_arm.mk)
