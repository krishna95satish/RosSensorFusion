// Copyright 2019 KPIT  [legal/copyright]

#include "rosbag_creation/Node.h"

cv_bridge::CvImagePtr& Node::RosImgToOpenCv(const sensor_msgs::Image::ConstPtr& rosImgMsg) {
    try {
        openCvFrame_ = cv_bridge::toCvCopy(rosImgMsg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e) {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.", rosImgMsg->encoding.c_str());
    }
    return openCvFrame_;
}

void Node::getData() {}
void Node::publish() {}
void Node::subscribe() {}
void Node::repeatTransmission() {}
int Node::length() {}
void Node::nextFrame() {}

Node::~Node() {
    delete(cameraInput_);
    delete(radarInput_);
}
