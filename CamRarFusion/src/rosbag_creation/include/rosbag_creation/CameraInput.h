// Copyright 2019 KPIT  [legal/copyright]
#pragma once
#include "Input.h"
#include <string>
#include <vector>

class CameraInput : public Input {
 protected:
    std::string fileName_;
    rosbag::Bag bagObj_;
    std::vector<std::string> topics_{""};
    sensor_msgs::ImagePtr camImgMsg_{nullptr};
    std::vector<sensor_msgs::ImagePtr> rosImgMsgList_;
 public:
    CameraInput() {}
    void setFileName(const std::string fname);
    bool isOpen();
    std::vector<sensor_msgs::ImagePtr>& readCamData(const std::string topicNameInRosBag);
    ~CameraInput();
};

