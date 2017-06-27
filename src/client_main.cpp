#define LOG_TAG "Ruiz-Client"

#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include "ulog.h"
#include "IRuizService.h"

int main(int argc, char *argv[])
{
    const char *msg = "The red quick fox jumps over a lazy brown goat.";

    (void) argc;
    (void) argv;
    ULOGI("%s is starting", LOG_TAG);

    srand(time(NULL));

#if 1
	android::sp<IRuizService> service;

    service = IRuizService::Stub::asInterface();

	service->sendString(msg);
	abort();
    service->sendInt64(rand() * rand());
    service->closeService();
#endif

    ULOGI("%s is exitting", LOG_TAG);
    return (0);
}
