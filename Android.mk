###################################################################
# Copyright (c) 2020 RogerYu.
###################################################################


LOCAL_PATH:= $(call my-dir)

###################################################################
#
#               SmartPointer
#
###################################################################
include $(CLEAR_VARS)

LOCAL_SRC_FILES := SmartPointer.cpp

LOCAL_SHARED_LIBRARIES := \
                       liblog \
                       libutils \

LOCAL_C_INCLUDES := \
                 system/core/include/cutils

LOCAL_MODULE_TAGS := optional
#LOCAL_PROPRIETARY_MODULE := true

LOCAL_MODULE := SmartPointer

include $(BUILD_EXECUTABLE)


