#ifndef __IRuizService_H
#define __IRuizService_H

#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/String16.h>

class IRuizService: public android::IInterface {
private:
	static const android::String16 descriptor;

public:
    class Stub: public android::IInterface {
    public:
		static const android::String16 descriptor;
		static android::String16 getInterfaceDescriptor();
        static android::sp<IRuizService> asInterface();
    };

    virtual const char *sendString(const char *data) = 0;
    virtual void sendInt64(int64_t data) = 0;
    virtual void closeService() = 0;
	static android::String16 getInterfaceDescriptor();

	/* TRANSACTION CODE */
    static const int TC_CSTRING = 1;
    static const int TC_INT32 = 2;
    static const int TC_INT64 = 3;
    static const int TC_CLOSE_SERVICE = 4;
};

#endif
