#ifndef _CORE_VEHICLE_MODEL_INCLUDE_VEHICLE_MODEL_CONTROLLERS_PURE_PURSUIT_CONTROLLER_H_
#define _CORE_VEHICLE_MODEL_INCLUDE_VEHICLE_MODEL_CONTROLLERS_PURE_PURSUIT_CONTROLLER_H_

#include "common/basics/basics.h"

namespace control {
/**
 * @brief Pure pursuit controller to let the vehicle follow a given path
 * ref to ``Automatic steering methods for autonomous automobile path tracking''
 * pp.10 by Snider et al.
 * @param look_ahead_dist may be set proportional to current velocity
 */
class PurePursuitControl {
  public:
    static ErrorType CalculateDesiredSteer(const decimal_t wheelbase_len,
                                           const decimal_t angle_diff,
                                           const decimal_t look_ahead_dist,
                                           decimal_t* steer);
};

} // namespace control

#endif // _CORE_VEHICLE_MODEL_INCLUDE_VEHICLE_MODEL_CONTROLLERS_PURE_PURSUIT_CONTROLLER_H_