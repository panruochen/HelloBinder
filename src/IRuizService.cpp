#define LOG_TAG "Ruiz-Client"

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <cutils/atomic.h>
#include <utils/Errors.h>
#include <utils/String16.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>

#include "ulog.h"
#include "IRuizService.h"

#define SERVICE_NAME "org.ruiz.service"

//////// Proxy Implementations ///////////////////////////////////////////
//
class RuizProxy : public android::BpInterface<IRuizService> {
public:
	RuizProxy(android::sp<android::IBinder> remote);
    const char *sendString(const char *arg);
    void sendInt64(int64_t arg);
    void closeService();
//	android::IBinder *onAsBinder();
};

RuizProxy:: RuizProxy(android::sp<android::IBinder> remote)
                : android::BpInterface<IRuizService>(remote)
{
}

#if 0
android::IBinder *RuizProxy::onAsBinder()
{
	return mRemote;
}
#endif

const char *RuizProxy::sendString(const char *arg)
{
    android::Parcel data, reply;
    data.writeInterfaceToken(IRuizService::getInterfaceDescriptor());
    data.writeCString(arg);
    remote()->transact(TC_CSTRING, data, &reply, android::IBinder::FLAG_ONEWAY);
	return reply.readCString();
}

void RuizProxy::sendInt64(int64_t arg)
{
    android::Parcel data, reply;
    data.writeInterfaceToken(IRuizService::getInterfaceDescriptor());
    data.writeInt64(arg);
    remote()->transact(TC_INT64, data, &reply, android::IBinder::FLAG_ONEWAY);
}

void RuizProxy::closeService()
{
    android::Parcel data, reply;
    data.writeInterfaceToken(IRuizService::getInterfaceDescriptor());
    remote()->transact(TC_CLOSE_SERVICE, data, &reply, android::IBinder::FLAG_ONEWAY);
}

//////// IRuizService::Stub Implementations ///////////////////////////////////////////
const android::String16 IRuizService::Stub::descriptor(SERVICE_NAME);

android::String16 IRuizService::Stub::getInterfaceDescriptor()
{
    return descriptor;
}

android::sp<IRuizService> IRuizService::Stub::asInterface()
{
	android::sp<android::IServiceManager> sm = android::defaultServiceManager();
	android::sp<android::IBinder> obj;
    android::sp<IRuizService> intr;

    obj = sm->getService(IRuizService::getInterfaceDescriptor());
    if (obj == NULL)
        return NULL;

    intr = static_cast<IRuizService*>(obj->queryLocalInterface(IRuizService::descriptor).get());
    if (intr == NULL)
        intr = new RuizProxy(obj);
    return intr;
}

//////// IRuizServie Implementations ///////////////////////////////////////////
const android::String16 IRuizService::descriptor(SERVICE_NAME);

android::String16 IRuizService::getInterfaceDescriptor()
{
    return descriptor;
}

