// Copyright 2019 KPIT  [legal/copyright]

#pragma once
#include <string>
#include "rosbag_creation/Node.h"
#include "rosbag_creation/RadarMsg.h"
#include "PolarToCartConverter.h"


class FusionNode : public Node {
 private:
    bool imageRecivedFlag_{0};
    bool radarRecivedFlag_{0};
    std::string imageID_{0};
    int radarID_{0};
    ros::NodeHandle nodeHandler_;
    ros::Subscriber msgSubscriber_;
    image_transport::Subscriber imageTransporterSub_;
    image_transport::Publisher imagePublisher_;
    image_transport::ImageTransport imageTransporter_;
    cv_bridge::CvImagePtr tempCameraBuffer_{nullptr};
    cv_bridge::CvImagePtr processedImgData_{nullptr};
    const std::string OPENCV_WINDOW = "Image window";
    PolarToCartConverter polarToCartConverter_;

 public:
    FusionNode();
    void finalPublisher();
    void repeatTransmission();
    void msgSubscriber();
    void msgPublisher();
    void plotting(const rosbag_creation::RadarMsg::ConstPtr& radar_msg);
    int getMsgSize();
    void goToNextMsg();
    void imageCallback(const sensor_msgs::Image::ConstPtr& cameraMsg);
    void radarCallback(const rosbag_creation::RadarMsg::ConstPtr& radarMsg);
    ~FusionNode() {}
};
