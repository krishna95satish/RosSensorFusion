// Copyright 2019 <KPIT>

#include "rosbag_creation/CameraPublisherNode.h"

CameraPublisherNode::CameraPublisherNode(const std::string fileName) {
    CameraInputObj_.setFileName(fileName);
}

void CameraPublisherNode::getInputData() {
    if (CameraInputObj_.isOpen()) {
        tempCamData_ = CameraInputObj_.readCamData(gtopicNameInRosBag);
    }
}

void CameraPublisherNode::msgPublisher() {
    ros::NodeHandle nodeHandler;
    image_transport::Publisher imagePublisher;
    image_transport::ImageTransport imageTransporter(nodeHandler);
    imagePublisher = imageTransporter.advertise("CamMsg", gQueueSize);
    ROS_INFO("size is [%d], [%d]", getMsgSize(), imgMsgCounter_);
    if (imgMsgCounter_ != getMsgSize()) {
        ROS_INFO("sending");
        ros::Duration(1).sleep();
        imagePublisher.publish(tempCamData_[imgMsgCounter_]);
        ROS_INFO("count is [%d]", imgMsgCounter_);
        goToNextMsg();
    } else {
        repeatTransmission();
    }
}

int CameraPublisherNode::getMsgSize() {
    return(tempCamData_.size());
}
void CameraPublisherNode::goToNextMsg() {
    imgMsgCounter_++;
}

void CameraPublisherNode::repeatTransmission() {
    imgMsgCounter_ = 0;
}

void CameraPublisherNode::process() {
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "CamNode");
    CameraPublisherNode CameraPublisherNode(gCameraNodeFile);
    CameraPublisherNode.getInputData();
    ros::Rate loop_rate(gPubBaudRate);
    while (ros::ok()) {
        CameraPublisherNode.msgPublisher();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
