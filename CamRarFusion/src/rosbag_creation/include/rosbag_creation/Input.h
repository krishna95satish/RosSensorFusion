// Copyright 2019 KPIT  [legal/copyright]
#pragma once

#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <string>
#include <vector>
#include "rosbag_creation/RadarMsg.h"


class Input {
 public:
    virtual void setFileName(const std::string fname) = 0;
    virtual bool isOpen() = 0;
    virtual std::vector<sensor_msgs::ImagePtr>& readCamData(const std::string topicNameInRosBag) {}
    virtual bool readRadarData(const std::string topicNameInRosBag) {}
};
