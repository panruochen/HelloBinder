#define LOG_TAG "Ruiz-Service"

#include <sys/types.h>
#include <unistd.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include "ulog.h"
#include "RuizService.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    ULOGI("%s is starting", LOG_TAG);
    RuizService::instantiate();
    android::ProcessState::self()->startThreadPool();
    ULOGI("%s is ready", LOG_TAG);

    android::IPCThreadState::self()->joinThreadPool();
    return(0);
}
