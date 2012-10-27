#include "common.h"

#ifndef CPLUSPLUS11

namespace this_thread
{
void sleep_for(time_duration abs_time)
{
    boost::this_thread::sleep(abs_time);
}
}

#endif
