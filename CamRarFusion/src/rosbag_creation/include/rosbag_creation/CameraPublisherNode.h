// Copyright 2019 <KPIT> [legal/copyright]

#ifndef CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_CAMERAPUBLISHERNODE_H_
#define CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_CAMERAPUBLISHERNODE_H_

#include <vector>
#include <string>
#include "CameraInput.h"
#include "Node.h"
#include "GlobalConsts.h"

class CameraPublisherNode : public Node {
 private:
    sensor_msgs::ImagePtr temporaryCameraData_;
    int frameCounter_{0};
    int frameID_;

 public:
    CameraPublisherNode() {}
    explicit CameraPublisherNode(const std::string fileName);
    void getData();
    void publish();
    void nextFrame();
    void close();
    ~CameraPublisherNode(){}
};

#endif  // CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_CAMERAPUBLISHERNODE_H_
