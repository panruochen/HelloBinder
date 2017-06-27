#ifndef __RuizService_H
#define __RuizService_H

#include "IRuizService.h"

class RuizService : public android::BnInterface<IRuizService::Stub>
{
public:
    static  void instantiate();

                 RuizService();
    virtual      ~RuizService();

    android::status_t onTransact(uint32_t code,
                                 const android::Parcel &data,
                                 android::Parcel *reply,
                                 uint32_t flags);
};

#endif
