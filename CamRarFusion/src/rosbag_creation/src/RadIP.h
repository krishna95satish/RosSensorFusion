#pragma once
#include "Input.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "ros/ros.h"


class RadIP : public Input {

 protected:
    int canMsgCounter_ {0};
    rosbag::Bag bagObj_;
    rosbag_creation::RadarMsg::ConstPtr rosBagRadarData_;
    std::vector<rosbag_creation::RadarMsg::ConstPtr> radarDataList_;
    int vecCounter_ {0};
    int vecSize_ {0};
    int debugMode_;
    int count_ {0};
    std::string fileName_;
    std::vector<std::string> topics_{""};
 public:
     RadIP() {};
     void setFileName(const std::string fname);
     bool isOpen();
     std::vector<rosbag_creation::RadarMsg::ConstPtr>& readRadarData(const std::string topicNameInRosBag);
     ~RadIP();
};


