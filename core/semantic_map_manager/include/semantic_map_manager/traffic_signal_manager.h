#ifndef _CORE_SEMANTIC_MAP_MANAGER_INCLUDE_SEMANTIC_MAP_MANAGER_TRAFFIC_SIGNAL_MANAGER_H_
#define _CORE_SEMANTIC_MAP_MANAGER_INCLUDE_SEMANTIC_MAP_MANAGER_TRAFFIC_SIGNAL_MANAGER_H_

#include "common/basics/basics.h"
#include "common/basics/semantics.h"

namespace semantic_map_manager {

class TrafficSignalManager {
  public:
    using State = common::State;
    using Lane = common::Lane;
    using SpeedLimit = common::SpeedLimit;
    using TrafficLight = common::TrafficLight;

    enum IntersectionType {
        kNotIntersect = 0,
        kSignalAhead,
        kSignalControlled
    };

    TrafficSignalManager();
    ErrorType Init();
    ErrorType LoadSignals();
    ErrorType UpdateSignals(const decimal_t time_elapsed);
    /**
     * @brief get the speed limit w.r.t a certain state and ref lane
     */
    ErrorType GetSpeedLimit(const State& state, const Lane& lane,
                            decimal_t* speed_limit) const;
    /**
     * @brief get the stopping state w.r.t a certain state and ref lane
     */
    ErrorType GetTrafficStoppingState(const State& state, const Lane& lane,
                                      State* stopping_state) const;

    inline vec_E<SpeedLimit> speed_limit_list() const {
        return speed_limit_list_;
    }
    inline vec_E<TrafficLight> traffic_light_list() const {
        return traffic_light_list_;
    }

  private:
    ErrorType CheckIntersectionTypeWithSignal(
        const common::FrenetState& fs, const Lane& lane,
        const common::TrafficSignal& signal,
        IntersectionType* intersection_type, decimal_t* dist_to_startpt,
        decimal_t* dist_to_endpt) const;
    vec_E<SpeedLimit> speed_limit_list_;
    vec_E<TrafficLight> traffic_light_list_;
};

} // namespace semantic_map_manager

#endif // _CORE_SEMANTIC_MAP_MANAGER_INCLUDE_SEMANTIC_MAP_MANAGER_TRAFFIC_SIGNAL_MANAGER_H_