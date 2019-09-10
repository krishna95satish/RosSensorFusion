// Copyright 2019 KPIT  [legal/copyright]
#pragma once
#include "Node.h"
#include <vector>
#include <string>

class RadarPublisherNode : public Node{
 private:
    std::vector<rosbag_creation::RadarMsg::ConstPtr> tempRadarData_;
    rosbag_creation::RadarMsg dummyRadarData_; // to compensate for missing frames
    int dummyMsgCounter_{0};
    int radarMsgCounter_{0};
 public:
    explicit RadarPublisherNode(const std::string fileName);
    void getInputData();
    void msgPublisher();
    void nextDummyMsg();
    void repeatTransmission();
    int getMsgSize();
    void goToNextMsg();
    ~RadarPublisherNode(){}
};
