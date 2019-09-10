// Copyright 2019 KPIT  [legal/copyright]

#include "rosbag_creation/Node.h"

cv_bridge::CvImagePtr& Node::RosImgToOpenCv(const sensor_msgs::Image::ConstPtr& rosImgMsg) {
    try {
        cvImgPtr_ = cv_bridge::toCvCopy(rosImgMsg, sensor_msgs::image_encodings::BGR8);
        return cvImgPtr_;
    }
    catch (cv_bridge::Exception& e) {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.", rosImgMsg->encoding.c_str());
    }
}

void Node::getInputData() {}
void Node::msgPublisher() {}
void Node::msgSubscriber() {}
void Node::process() {}
void Node::repeatTransmission() {}
int Node::getMsgSize() {}
void Node::goToNextMsg() {}
