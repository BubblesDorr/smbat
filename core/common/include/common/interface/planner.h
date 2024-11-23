#ifndef _CORE_COMMON_INCLUDE_COMMON_INTERFACE_PLANNER_H_
#define _CORE_COMMON_INCLUDE_COMMON_INTERFACE_PLANNER_H_

#include "common/basics/basics.h"

#include <string>

// todo: move this interface out of the common file
namespace planning {
/**
 * @brief A general base class for different planners including
 * path/motion/behavior planners
 */
class Planner {
  public:
    Planner() = default;

    virtual ~Planner() = default;

    virtual std::string Name() = 0;

    virtual ErrorType Init(const std::string config) = 0;

    virtual ErrorType RunOnce() = 0;
};

} // namespace planning

#endif // _CORE_COMMON_INCLUDE_COMMON_INTERFACE_PLANNER_H_