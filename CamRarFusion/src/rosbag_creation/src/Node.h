#pragma once
#include <iostream>
#include "Input.h"
#include "Node.h"
#include <typeinfo>
#include "GlobalConsts.h"
#include <ros/ros.h>
#include "rosbag/bag.h"
#include <vector>
#include <rosbag/view.h>
#include <cv_bridge/cv_bridge.h>
#include <typeinfo>
#include "CamIP.h"
#include "RadIP.h"
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
    CamIP CamIPObj_;
    RadIP RadIPObj_;


 public:
    Node():imageTransportObj_(genericNodeHndl_) {};
 	
 	cv_bridge::CvImagePtr& RosImgToOpenCv(sensor_msgs::ImagePtr& rosImgMsg);
 	sensor_msgs::ImagePtr& openCVImgToRosImg();
    virtual void getInputData();
    virtual void msgPublisher();
    virtual void msgSubscriber();
    virtual void process();
    virtual ~Node(){};
};
