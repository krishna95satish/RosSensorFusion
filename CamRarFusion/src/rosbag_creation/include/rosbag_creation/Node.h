// Copyright 2019 KPIT  [legal/copyright]

#pragma once

#include "Input.h"
#include "Node.h"
#include "CameraInput.h"
#include "RadarInput.h"
#include "GlobalConsts.h"
#include "rosbag/bag.h"
#include <rosbag/view.h>
#include <ros/ros.h>
#include <iostream>
#include <vector>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <image_transport/image_transport.h>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <sstream>
#include <sensor_msgs/image_encodings.h>

class Node {
 protected:
    ros::NodeHandle genericNodeHndl_;
    ros::Publisher genericPublisherObject_;
    ros::Subscriber genericSubscriberObject_;
    image_transport::ImageTransport imageTransportObj_;
    image_transport::Publisher videoPubObj_;
    std::vector<std::string> topics_{""};
    cv_bridge::CvImagePtr cvImgPtr_;
    sensor_msgs::ImagePtr rosImgMsg_{nullptr};
    CameraInput CameraInputObj_;
    RadarInput RadarInputObj_;

 public:
    Node():imageTransportObj_(genericNodeHndl_) {}
    cv_bridge::CvImagePtr& RosImgToOpenCv(const sensor_msgs::Image::ConstPtr& rosImgMsg);
    virtual void getInputData();
    virtual void msgPublisher();
    virtual void msgSubscriber();
    virtual void repeatTransmission();
    virtual void process();
    virtual int getMsgSize();
    virtual void goToNextMsg();
    virtual ~Node(){}
};
