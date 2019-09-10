// Copyright 2019 KPIT  [legal/copyright]
#include "rosbag_creation/RadarInput.h"

void RadarInput::setFileName(const std::string fname) {
    fileName_ = fname;
}

bool RadarInput::isOpen() {
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

bool RadarInput::readRadarData(const std::string topicNameInRosBag) {
    topics_.push_back(topicNameInRosBag);
    ROS_INFO("reading.");
    ROS_INFO("topic name is [%s]", topics_);
    rosbag::View view(bagObj_, rosbag::TopicQuery(topics_));
    for (rosbag::MessageInstance const rosBagConstMsg : rosbag::View(bagObj_)) {
        rosBagRadarData_  = rosBagConstMsg.instantiate<rosbag_creation::RadarMsg>();
        if (rosBagRadarData_  != NULL) {
            ROS_INFO("reading..... radar");
            ROS_INFO("v name is [%d]", rosBagRadarData_->frame);
            radarDataList_.push_back(rosBagRadarData_);
        } else {
            return 0;
        }
}
}
std::vector<rosbag_creation::RadarMsg::ConstPtr>& RadarInput::getMsgData() {
    return radarDataList_;
}
RadarInput::~RadarInput() {
    bagObj_.close();
}
