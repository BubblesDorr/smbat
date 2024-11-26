#ifndef _CORE_FORWARD_SIMULATOR_INCLUDE_FORWARD_SIMULATOR_MULTIMODAL_FORWARD_H_
#define _CORE_FORWARD_SIMULATOR_INCLUDE_FORWARD_SIMULATOR_MULTIMODAL_FORWARD_H_

#include "common/basics/basics.h"
#include "forward_simulator/onlane_forward_simulation.h"

namespace planning {

class MultiModalForward {
  public:
    using GridMap = common::GridMapND<uint8_t, 2>;
    typedef int AggressivenessLevel;

    static ErrorType ParamLookUp(const AggressivenessLevel& agg_level,
                                 OnLaneForwardSimulation::Param* param);
};

} // namespace planning

#endif // _CORE_FORWARD_SIMULATOR_INCLUDE_FORWARD_SIMULATOR_MULTIMODAL_FORWARD_H_