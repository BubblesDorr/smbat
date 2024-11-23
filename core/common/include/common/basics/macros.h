#ifndef _CORE_COMMON_INCLUDE_COMMON_BASICS_MACROS_H_
#define _CORE_COMMON_INCLUDE_COMMON_BASICS_MACROS_H_

#define DECLARE_BACKWARD                                                       \
    namespace backward {                                                       \
    backward::SignalHandling sh;                                               \
    }

#endif // _CORE_COMMON_INCLUDE_COMMON_BASICS_MACROS_H_