#!/bin/sh
set -e

SERVICE_EXEC=ruiz-service
CLIENT_EXEC=ruiz-client
RUN_DIR=/data/tmp

if [ "$1" = build ]; then
  (
    cd $ANDROID_BUILD_TOP
	make $SERVICE_EXEC $CLIENT_EXEC
	adb root
	adb wait-for-device
	adb shell "mkdir -p $RUN_DIR"
	adb push $ANDROID_PRODUCT_OUT/system/bin/$SERVICE_EXEC $RUN_DIR
	adb push $ANDROID_PRODUCT_OUT/system/bin/$CLIENT_EXEC  $RUN_DIR
  )
fi

adb root
adb wait-for-device

adb shell <<__EOF__
cd $RUN_DIR
./$SERVICE_EXEC &
sleep 3 # wait for service up
./$CLIENT_EXEC
sleep 1
__EOF__
