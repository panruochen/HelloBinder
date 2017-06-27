LOCAL_PATH := $(call my-dir)

######################################################################################
include $(CLEAR_VARS)

LOCAL_SRC_FILES := src/service_main.cpp src/IRuizService.cpp src/RuizService.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/src

LOCAL_MODULE := ruiz-service

LOCAL_SHARED_LIBRARIES += liblog libbinder
LOCAL_SHARED_LIBRARIES += libutils

include $(BUILD_EXECUTABLE)

######################################################################################
include $(CLEAR_VARS)

LOCAL_SRC_FILES := src/client_main.cpp src/IRuizService.cpp src/RuizService.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/src

LOCAL_MODULE := ruiz-client

LOCAL_SHARED_LIBRARIES += liblog libbinder
LOCAL_SHARED_LIBRARIES += libutils

include $(BUILD_EXECUTABLE)
######################################################################################
