// Copyright 2019 KPIT  [legal/copyright]

#include "rosbag_creation/RadarPublisherNode.h"
#include "rosbag_creation/GlobalConsts.h"
#include "rosbag_creation/Ros.h"

RadarPublisherNode::RadarPublisherNode(const std::string fileName) {
    radarInput_->setFileName(fileName);
    publish_ = node_.advertise<rosbag_creation::RadarMsg>(gRadarMsgname, gQueueSize);
}

void RadarPublisherNode::getData() {
    if (radarInput_->open()) {
        radarInput_->read(gRadarTopicname);
        tempRadarData_ = radarInput_->getData();
        radarInput_->close();
    }
}

// Logic to compensate the missing frames in CSV Radar Data
void RadarPublisherNode::publish() {
    ROS_INFO("Publishing Radar Data");
    if (radarMsgCounter_ != length()) {
        if (tempRadarData_[radarMsgCounter_]->frame_ > dummyMsgCounter_) {
            dummyRadarData_.frame_ = dummyMsgCounter_;
            dummyRadarData_.radarAngle_ = gRadarplotconstant;
            dummyRadarData_.radarRange_ = gRadarplotconstant;
            publish_.publish(dummyRadarData_);
            nextDummyMsg();
        } else {
        publish_.publish(tempRadarData_[radarMsgCounter_]);
        nextDummyMsg();
        nextFrame();
        }
    } else {
        repeatTransmission();
    }
}

void RadarPublisherNode::nextDummyMsg() {
    dummyMsgCounter_++;
}

int RadarPublisherNode::length() {
    return(tempRadarData_.size());
}

void RadarPublisherNode::nextFrame() {
    radarMsgCounter_++;
}

void RadarPublisherNode::repeatTransmission() {
    radarMsgCounter_ = gFrameReset;
}

int main(int argc, char** argv) {
    Ros ros_;
    ros_.initialize(argc, argv, gRadarPublisherNode);
    RadarPublisherNode radarPublisherNode(gRadarNodeFile);
    radarPublisherNode.getData();
    ros::Rate loop_rate(gPublisherBaudRate);
    while (ros::ok()) {
        radarPublisherNode.publish();
        ros_.rate();
        loop_rate.sleep();
    }
    return 0;
}
