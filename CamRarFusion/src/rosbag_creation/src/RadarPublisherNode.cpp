// Copyright 2019 KPIT  [legal/copyright]
#include "rosbag_creation/RadarPublisherNode.h"

RadarPublisherNode::RadarPublisherNode(const std::string fileName) {
    RadarInputObj_.setFileName(fileName);
}

void RadarPublisherNode::getInputData() {
    if (RadarInputObj_.isOpen()) {
        RadarInputObj_.readRadarData("/RadarDataTopic");
        tempRadarData_ = RadarInputObj_.getMsgData();
    }
    process();
}
void RadarPublisherNode::msgPublisher() {
    genericPublisherObject_ = genericNodeHndl_.advertise<rosbag_creation::RadarMsg>("RadarMsg", gQueueSize);
    ROS_INFO("size is [%d], [%d]", getMsgSize(), radarMsgCounter_);
    if (radarMsgCounter_ != getMsgSize()) {
        ROS_INFO("sending");
        ros::Duration(5).sleep();
        if(tempRadarData_[radarMsgCounter_]->frame > dummyMsgCounter_) {
            dummyRadarData_.frame = dummyMsgCounter_;
            dummyRadarData_.radarAngle = -100000;
            dummyRadarData_.radarRange = -100000;
            genericPublisherObject_.publish(dummyRadarData_);
            nextDummyMsg();
        } else {
        genericPublisherObject_.publish(tempRadarData_[radarMsgCounter_]);
        ROS_INFO("count is [%d]", radarMsgCounter_);
        nextDummyMsg();
        goToNextMsg();
        }
        
        

    } else {
        repeatTransmission();
    }
}
void RadarPublisherNode::nextDummyMsg() {
    dummyMsgCounter_++;
}

int RadarPublisherNode::getMsgSize() {
    return(tempRadarData_.size());
}
void RadarPublisherNode::goToNextMsg() {
    radarMsgCounter_++;
}

void RadarPublisherNode::repeatTransmission() {
    radarMsgCounter_ = 0;
}


int main(int argc, char** argv) {
    ros::init(argc, argv, "RadarNode");
    RadarPublisherNode cameraPubNode("/home/kpit/CamRarFusion/RosbagInput/radardata.bag");
    cameraPubNode.getInputData();
    ros::Rate loop_rate(gPubBaudRate);
    while (ros::ok()) {
        cameraPubNode.msgPublisher();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
