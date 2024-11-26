#ifndef _CORE_PHY_SIMULATOR_INCLUDE_PHY_SIMULATOR_VISUALIZER_H_
#define _CORE_PHY_SIMULATOR_INCLUDE_PHY_SIMULATOR_VISUALIZER_H_

#include "common/basics/semantics.h"
#include "phy_simulator/phy_simulator.h"

#include <ros/ros.h>

namespace phy_simulator {

class Visualizer {
  public:
    Visualizer() {}
    Visualizer(ros::NodeHandle nh);
    ~Visualizer() {}

    void set_phy_sim(PhySimulation* p_phy_sim) { p_phy_sim_ = p_phy_sim; }

    void VisualizeData();
    void VisualizeDataWithStamp(const ros::Time& stamp);
    void SendTfWithStamp(const ros::Time& stamp);

  private:
    void VisualizeVehicleSet(const ros::Time& stamp,
                             const common::VehicleSet& vehicle_set);
    void VisualizeLaneNet(const ros::Time& stamp,
                          const common::LaneNet& lane_net);
    void VisualizeObstacleSet(const ros::Time& stamp,
                              const common::ObstacleSet& Obstacle_set);

    ros::NodeHandle nh_;

    ros::Publisher vehicle_set_pub_;
    ros::Publisher lane_net_pub_;
    ros::Publisher obstacle_set_pub_;

    PhySimulation* p_phy_sim_;
}; // Visualizer

} // namespace phy_simulator

#endif // _CORE_PHY_SIMULATOR_INCLUDE_PHY_SIMULATOR_VISUALIZER_H_