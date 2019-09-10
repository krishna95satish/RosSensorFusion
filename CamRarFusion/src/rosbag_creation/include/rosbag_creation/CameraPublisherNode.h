// Copyright 2019 <KPIT> [legal/copyright]

#pragma once
#include "Node.h"
#include <vector>
#include <string>

class CameraPublisherNode : public Node {
 private:
    std::vector<sensor_msgs::ImagePtr> tempCamData_;
    int imgMsgCounter_{0};

 public:
    explicit CameraPublisherNode(const std::string fileName);
    void getInputData();
    void msgPublisher();
    void repeatTransmission();
    void process();
    int getMsgSize();
    void goToNextMsg();
    ~CameraPublisherNode(){}
};
