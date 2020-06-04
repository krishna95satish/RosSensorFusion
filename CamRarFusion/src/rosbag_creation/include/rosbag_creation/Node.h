// Copyright 2019 KPIT  [legal/copyright]

#ifndef CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_NODE_H_
#define CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_NODE_H_

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "Input.h"
#include "CameraInput.h"
#include "RadarInput.h"
#include "Include.h"
#include <string>
#include <vector>

class Node {
 protected:
    ros::NodeHandle node_;
    ros::Publisher publish_;
    ros::Subscriber subscribe_;
    image_transport::ImageTransport imageTransport_;
    image_transport::Publisher videoPublisher_;
    std::vector<std::string> topics_{""};
    cv_bridge::CvImagePtr openCvFrame_;

 public:
    Node():imageTransport_(node_) {}
    CameraInput *cameraInput_ = CameraInput::newinstance();
    RadarInput *radarInput_ = RadarInput::newinstance();
    cv_bridge::CvImagePtr& RosImgToOpenCv(const sensor_msgs::Image::ConstPtr& rosImgMsg);
    virtual void getData();
    virtual void publish();
    virtual void subscribe();
    virtual void repeatTransmission();
    virtual int length();
    virtual void nextFrame();
    virtual ~Node();
};

#endif  // CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_NODE_H_
