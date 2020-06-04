// Copyright 2019 KPIT  [legal/copyright]

#include "rosbag_creation/Ros.h"
#include "rosbag_creation/GlobalConsts.h"

void Ros::initialize(int argc, char** argv, const std::string nodename) {
    ros::init(argc, argv, nodename);
}

void Ros::spin() {
    ros::spin();
}

void Ros::rate() {
    ros::spinOnce();
}
