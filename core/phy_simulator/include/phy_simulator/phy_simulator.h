#ifndef _CORE_PHY_SIMULATOR_INCLUDE_PHY_SIMULATOR_PHY_SIMULATOR_H_
#define _CORE_PHY_SIMULATOR_INCLUDE_PHY_SIMULATOR_PHY_SIMULATOR_H_

#include "common/basics/semantics.h"
#include "phy_simulator/arena_loader.h"
#include "vehicle_model/vehicle_model.h"

#include <string>
#include <unordered_map>
#include <vector>
namespace phy_simulator {

class PhySimulation {
  public:
    PhySimulation();
    PhySimulation(const std::string& vehicle_set_path,
                  const std::string& map_path,
                  const std::string& lane_net_path);
    ~PhySimulation() {}

    common::LaneNet lane_net() const { return lane_net_; }
    common::ObstacleSet obstacle_set() const { return obstacle_set_; };
    common::VehicleSet vehicle_set() const { return vehicle_set_; }
    const std::vector<int> vehicle_ids() const { return vehicle_ids_; }

    bool AddTemporaryObstacleToMap(const common::Point& pt, const double& size);
    bool RemoveTemporaryObstacle(const common::Point& pt, const double& s);

    bool UpdateSimulatorUsingSignalSet(
        const common::VehicleControlSignalSet& signal_set, const decimal_t& dt);

  private:
    bool GetDataFromArenaLoader();

    bool SetupVehicleModelForVehicleSet();

    bool UpdateVehicleStates(const common::VehicleControlSignalSet& signal_set,
                             const decimal_t& dt);

    ArenaLoader* p_arena_loader_;

    common::VehicleSet vehicle_set_;
    std::unordered_map<int, simulator::VehicleModel> vehicle_model_set_;
    std::vector<int> vehicle_ids_;

    common::LaneNet lane_net_;
    common::ObstacleSet obstacle_set_;

    int temp_obstacle_cnt_ = 0;
    int temp_obs_idx_offset_ = 10000;
    std::unordered_map<int, common::PolygonObstacle> temp_obstacle_set_;
};

} // namespace phy_simulator

#endif // _CORE_PHY_SIMULATOR_INCLUDE_PHY_SIMULATOR_PHY_SIMULATOR_H_