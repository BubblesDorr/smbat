#ifndef _CORE_BEHAVIOR_PLANNER_INCLUDE_BEHAVIOR_PLANNER_BEHAVIOR_SERVER_ROS_H_
#define _CORE_BEHAVIOR_PLANNER_INCLUDE_BEHAVIOR_PLANNER_BEHAVIOR_SERVER_ROS_H_

#include "behavior_planner/behavior_planner.h"
#include "behavior_planner/map_adapter.h"
#include "behavior_planner/visualizer.h"
#include "common/basics/tic_toc.h"
#include "common/visualization/common_visualization_util.h"
#include "moodycamel/atomicops.h"
#include "moodycamel/readerwriterqueue.h"
#include "semantic_map_manager/semantic_map_manager.h"

#include <sensor_msgs/Joy.h>

#include <functional>
#include <ros/ros.h>

namespace planning {
class BehaviorPlannerServer {
  public:
    using SemanticMapManager = semantic_map_manager::SemanticMapManager;

    struct Config {
        int kInputBufferSize{100};
    };

    BehaviorPlannerServer(ros::NodeHandle nh, int ego_id);

    BehaviorPlannerServer(ros::NodeHandle nh, double work_rate, int ego_id);

    void PushSemanticMap(const SemanticMapManager& smm);

    void BindBehaviorUpdateCallback(
        std::function<int(const SemanticMapManager&)> fn);

    /**
     * @brief set the level of autonomous driving
     */
    void set_autonomous_level(int level);

    /**
     * @brief set desired velocity
     */
    void set_user_desired_velocity(const decimal_t desired_vel);

    void set_aggressive_level(int level);

    decimal_t user_desired_velocity() const;

    decimal_t reference_desired_velocity() const;

    void enable_hmi_interface();

    void Init();

    void Start();

  private:
    void PlanCycleCallback();

    void JoyCallback(const sensor_msgs::Joy::ConstPtr& msg);

    void Replan();

    void PublishData();

    void MainThread();

    Config config_;

    BehaviorPlanner bp_;
    BehaviorPlannerMapAdapter map_adapter_;
    BehaviorPlannerVisualizer* p_visualizer_;

    TicToc time_profile_tool_;
    decimal_t global_init_stamp_{0.0};

    // ros related
    ros::NodeHandle nh_;
    ros::Subscriber joy_sub_;

    double work_rate_;
    int ego_id_;

    // input buffer
    moodycamel::ReaderWriterQueue<SemanticMapManager>* p_input_smm_buff_;

    bool has_callback_binded_ = false;
    std::function<int(const SemanticMapManager&)> private_callback_fn_;

    bool is_hmi_enabled_ = false;
};

} // namespace planning

#endif // _CORE_BEHAVIOR_PLANNER_INCLUDE_BEHAVIOR_PLANNER_BEHAVIOR_SERVER_ROS_H_