#pragma once

#include <array>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include "drive_msgs/drive_param.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Float64.h"
#include <ros/console.h>
#include <ros/ros.h>

constexpr float DEG_TO_RAD = M_PI / 180.0;

constexpr const char* TOPIC_LASER_SCAN = "/scan";
constexpr const char* TOPIC_EMERGENCY_STOP = "/emergency_stop";

constexpr float SAMPLE_ANGLE = 6 * DEG_TO_RAD;
constexpr float RANGE_THRESHOLD = 0.7;

constexpr float MAX_RANGE = 30;

class EmergencyStop
{
    public:
    EmergencyStop();

    private:
    /**
     * @brief Returns true if there is a wall too close in front of the car.
     */
    bool emergencyStop(const sensor_msgs::LaserScan::ConstPtr& lidar);

    ros::NodeHandle m_node_handle;
    ros::Subscriber m_lidar_subscriber;

    void lidarCallback(const sensor_msgs::LaserScan::ConstPtr& lidar);

    ros::Publisher m_emergency_stop_publisher;
};