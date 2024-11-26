#ifndef _CORE_FORWARD_SIMULATOR_INCLUDE_FORWARD_SIMULATOR_ONLANE_FORWARD_SIMULATION_H_
#define _CORE_FORWARD_SIMULATOR_INCLUDE_FORWARD_SIMULATOR_ONLANE_FORWARD_SIMULATION_H_

#include "common/basics/semantics.h"
#include "common/lane/lane.h"
#include "common/state/frenet_state.h"
#include "common/state/state.h"
#include "common/state/state_transformer.h"
#include "vehicle_model/controllers/ctx_idm_velocity_controller.h"
#include "vehicle_model/controllers/idm_velocity_controller.h"

namespace planning {

class OnLaneForwardSimulation {
  public:
    using CtxParam = simulator::ContextIntelligentDriverModel::CtxParam;
    using IdmParam = simulator::IntelligentDriverModel::Param;

    struct Param {
        IdmParam idm_param;
        decimal_t steer_control_gain = 1.5;
        decimal_t steer_control_max_lookahead_dist = 50.0;
        decimal_t steer_control_min_lookahead_dist = 3.0;
        decimal_t max_lat_acceleration_abs = 1.5;
        decimal_t max_lat_jerk_abs = 3.0;
        decimal_t max_curvature_abs = 0.33;
        decimal_t max_lon_acc_jerk = 5.0;
        decimal_t max_lon_brake_jerk = 5.0;
        decimal_t max_steer_angle_abs = 45.0 / 180.0 * kPi;
        decimal_t max_steer_rate = 0.39;
        bool auto_decelerate_if_lat_failed = true;
    };

    static ErrorType
    GetTargetStateOnTargetLane(const common::StateTransformer& stf_target,
                               const common::Vehicle& ego_vehicle,
                               const common::Vehicle& gap_front_vehicle,
                               const common::Vehicle& gap_rear_vehicle,
                               const Param& param, common::State* target_state);

    static ErrorType PropagateOnceAdvancedLK(
        const common::StateTransformer& stf, const common::Vehicle& ego_vehicle,
        const common::Vehicle& leading_vehicle,
        const decimal_t& lat_track_offset, const decimal_t& dt,
        const Param& param, common::State* desired_state);

    static ErrorType
    PropagateOnceAdvancedLC(const common::StateTransformer& stf_current,
                            const common::StateTransformer& stf_target,
                            const common::Vehicle& ego_vehicle,
                            const common::Vehicle& current_leading_vehicle,
                            const common::Vehicle& gap_front_vehicle,
                            const common::Vehicle& gap_rear_vehicle,
                            const decimal_t& lat_track_offset,
                            const decimal_t& dt, const Param& param,
                            common::State* desired_state);

    static ErrorType PropagateOnce(const common::StateTransformer& stf,
                                   const common::Vehicle& ego_vehicle,
                                   const common::Vehicle& leading_vehicle,
                                   const decimal_t& dt, const Param& param,
                                   common::State* desired_state);

    // ~ Propagate using const velocity and steer
    static ErrorType PropagateOnce(const decimal_t& desired_vel,
                                   const common::Vehicle& ego_vehicle,
                                   const decimal_t& dt, const Param& param,
                                   common::State* desired_state);

  private:
    static ErrorType GetIdmEquivalentVehicleLength(
        const common::StateTransformer& stf, const common::Vehicle& ego_vehicle,
        const common::Vehicle& leading_vehicle,
        const common::FrenetState& leading_fs, decimal_t* eqv_vehicle_len);

    static ErrorType CalcualateSteer(const common::StateTransformer& stf,
                                     const common::State& current_state,
                                     const common::FrenetState& current_fs,
                                     const decimal_t& wheelbase_len,
                                     const Vec2f& lookahead_offset,
                                     decimal_t* steer);

    // ~ Using leading vehicle
    static ErrorType CalcualateVelocityUsingIdm(
        const decimal_t& current_pos, const decimal_t& current_vel,
        const decimal_t& leading_pos, const decimal_t& leading_vel,
        const decimal_t& dt, const Param& param, decimal_t* velocity);

    static ErrorType CalcualateVelocityUsingIdm(const decimal_t& current_vel,
                                                const decimal_t& dt,
                                                const Param& param,
                                                decimal_t* velocity);

    static ErrorType CalcualateVelocityUsingCtxIdm(
        const decimal_t& current_pos, const decimal_t& current_vel,
        const decimal_t& leading_pos, const decimal_t& leading_vel,
        const decimal_t& target_pos, const decimal_t& target_vel,
        const decimal_t& dt, const Param& param, const CtxParam& ctx_param,
        decimal_t* velocity);

    static ErrorType CalcualateVelocityUsingCtxIdm(
        const decimal_t& current_pos, const decimal_t& current_vel,
        const decimal_t& target_pos, const decimal_t& target_vel,
        const decimal_t& dt, const Param& param, const CtxParam& ctx_param,
        decimal_t* velocity);

    static ErrorType
    CalculateDesiredState(const common::State& current_state,
                          const decimal_t steer, const decimal_t velocity,
                          const decimal_t wheelbase_len, const decimal_t dt,
                          const Param& param, common::State* state);
};

} // namespace planning

#endif // _CORE_FORWARD_SIMULATOR_INCLUDE_FORWARD_SIMULATOR_ONLANE_FORWARD_SIMULATION_H_