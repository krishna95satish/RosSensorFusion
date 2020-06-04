// Copyright 2019 KPIT  [legal/copyright]

#ifndef CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_RADARPUBLISHERNODE_H_
#define CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_RADARPUBLISHERNODE_H_

#include <vector>
#include <string>
#include "Node.h"

class RadarPublisherNode : public Node {
 private:
    std::vector<rosbag_creation::RadarMsg::ConstPtr> tempRadarData_;
    rosbag_creation::RadarMsg dummyRadarData_;  // to compensate for missing frames
    int dummyMsgCounter_{0};
    int radarMsgCounter_{0};
 public:
    explicit RadarPublisherNode(const std::string fileName);
    void getData();
    void publish();
    void nextDummyMsg();
    void repeatTransmission();
    int length();
    void nextFrame();
    ~RadarPublisherNode(){}
};

#endif  // CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_RADARPUBLISHERNODE_H_
