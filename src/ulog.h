#ifndef __ULOG_H
#define __ULOG_H

#include <stdio.h>
#include <utils/Log.h>

#if 0
#define ULOGV(fmt,args...)  ALOGV(fmt,##args)
#define ULOGI(fmt,args...)  ALOGI(fmt,##args)
#define ULOGE(fmt,args...)  ALOGE(fmt,##args)
#else
#define ULOGV(fmt,args...)  do { fprintf(stdout, fmt "\n", ##args); fflush(stdout); } while(0)
#define ULOGI(fmt,args...)  do { fprintf(stdout, fmt "\n", ##args); fflush(stdout); } while(0)
#define ULOGE(fmt,args...)  fprintf(stderr, fmt "\n", ##args)
#endif

#endif
