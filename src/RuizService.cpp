#define LOG_TAG "Ruiz-Service"

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <cutils/atomic.h>
#include <utils/Errors.h>
#include <utils/String16.h>
#include <binder/IServiceManager.h>

#include "ulog.h"
#include "RuizService.h"

void RuizService::instantiate()
{
    ULOGI("%s %u", __func__, __LINE__);
	RuizService *service = new RuizService();
    ULOGI("%s %u", __func__, __LINE__);
    android::defaultServiceManager()->addService(
        IRuizService::getInterfaceDescriptor(), service);
    ULOGI("%s %u", __func__, __LINE__);
}

RuizService::RuizService()
{
    ULOGI("%s created", LOG_TAG);
}

RuizService::~RuizService()
{
    ULOGI("%s destroyed", LOG_TAG);
}

android::status_t RuizService::onTransact(uint32_t code,
    const android::Parcel &data, android::Parcel *reply, uint32_t flags)
{
    android::String16 interface;
    ULOGE("Service (PID_%u) OnTransact(%u,%u)", getpid(), code, flags);

	sleep(2);
    data.enforceInterface(interface);
//  CHECK_INTERFACE(IRuizService, data, reply);
    switch(code) {
	case IRuizService::TC_CSTRING: {
        const char *msg;
        msg = data.readCString();
		reply->writeCString("I got you!");
        ULOGI("[STRING]  %s\n", msg);
        return android::NO_ERROR;
    }
    case IRuizService::TC_INT64: {
        int64_t val;
        val = data.readInt64();
        ULOGI("[INT64]  %ld", val);
        return android::NO_ERROR;
    }

    case IRuizService::TC_CLOSE_SERVICE:
        ULOGI("[CLOSE]");
        exit(0);

    default:
        return BBinder::onTransact(code, data, reply, flags);
    }
    return android::NO_ERROR;
}

