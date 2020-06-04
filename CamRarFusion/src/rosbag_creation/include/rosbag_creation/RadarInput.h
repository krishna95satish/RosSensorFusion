// Copyright 2019 KPIT  [legal/copyright]

#ifndef CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_RADARINPUT_H_
#define CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_RADARINPUT_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Input.h"
#include "ros/ros.h"

class RadarInput : public Input {
 private:
    RadarInput() {}
    static RadarInput *RadarInputptr;

 protected:
    rosbag::Bag bag_;
    rosbag_creation::RadarMsg::ConstPtr radarFrame_;
    std::vector<rosbag_creation::RadarMsg::ConstPtr> radarFrames_;
    std::string fileName_;
    std::vector<std::string> topics_{""};
    bool statusFlag_;

 public:
    void setFileName(const std::string fname);
    bool open();
    void close();
    void read(const std::string topicNameInRosBag);
    std::vector<rosbag_creation::RadarMsg::ConstPtr>& getData();
    static RadarInput* newinstance();
    ~RadarInput();
};

#endif  // CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_RADARINPUT_H_
