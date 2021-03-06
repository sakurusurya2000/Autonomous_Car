#pragma once

#include "optimization/leastsquares1.h"
#include <ros/ros.h>
#include <string>

class VESCSimulator
{
    public:
    VESCSimulator();
    ~VESCSimulator();
    inline void setServoAngle(const double& data)
    {
        this->m_servo_data = data;
    }
    inline void setSpeed(const double& data)
    {
        this->m_state_speed = data;
    }
    void start();
    void stop();

    private:
    ros::NodeHandle m_node_handle;
    ros::Publisher m_odometry_publisher;
    ros::Timer m_timer;
    ros::Time m_last_stamp;

    bool m_started;
    double m_yaw;
    double m_servo_data;
    double m_state_speed;
    double m_x_position;
    double m_y_position;
    double m_x_dot;
    double m_y_dot;
    double m_current_speed;
    double m_current_steering_angle;
    double m_current_angular_velocity;
    double m_frequency;
    std::string m_odom_frame;
    std::string m_base_frame;
    LeastSquares1* m_optim_x_dot;
    LeastSquares1* m_optim_y_dot;
    LeastSquares1* m_optim_x_pos;
    LeastSquares1* m_optim_y_pos;
    LeastSquares1* m_optim_cur_ang_vel;

    void timerCallback(const ros::TimerEvent& event);
};