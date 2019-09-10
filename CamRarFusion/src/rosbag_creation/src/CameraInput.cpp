// Copyright 2019 KPIT  [legal/copyright]
#include "rosbag_creation/CameraInput.h"

void CameraInput::setFileName(const std::string fname) {
    fileName_ = fname;
}

bool CameraInput::isOpen() {
    try {
        ROS_INFO("file name is  [%s]", fileName_.c_str());
        bagObj_.open(fileName_, rosbag::bagmode::Read);
        return 1;
    }
    catch(rosbag::BagIOException& errMsg) {
        ROS_INFO("file name is  [%s]", errMsg.what());
        return 0;
    }
}

std::vector<sensor_msgs::ImagePtr>& CameraInput::readCamData(const std::string topicNameInRosBag) {
    topics_.push_back(topicNameInRosBag);
    ROS_INFO("topic name is [%s]", topics_);
    rosbag::View view(bagObj_, rosbag::TopicQuery(topics_));
    for (rosbag::MessageInstance const rosBagConstMsg : rosbag::View(bagObj_)) {
        ROS_INFO("reading.....");
        camImgMsg_ = rosBagConstMsg.instantiate<sensor_msgs::Image>();
        if (camImgMsg_ != NULL) {
            rosImgMsgList_.push_back(camImgMsg_);
        }
}
return(rosImgMsgList_);
}

CameraInput::~CameraInput() {
    bagObj_.close();
}

