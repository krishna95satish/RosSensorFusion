// Copyright 2019 <KPIT>

#include "rosbag_creation/CameraPublisherNode.h"
#include "rosbag_creation/GlobalConsts.h"
#include "rosbag_creation/Ros.h"

CameraPublisherNode::CameraPublisherNode(const std::string fileName) {
    cameraInput_->setFileName(fileName);
    videoPublisher_ = imageTransport_.advertise(gCameraMsgname, gQueueSize);
}

void CameraPublisherNode::getData() {
    if (cameraInput_->open()) {
        cameraInput_->read(gCameraBagName);
    }
}

void CameraPublisherNode::publish() {
    temporaryCameraData_ = cameraInput_->getData();
    frameID_ = atoi(temporaryCameraData_->header.frame_id.c_str());
    videoPublisher_.publish(temporaryCameraData_);
    ROS_INFO("Publishing CameraData...");
    nextFrame();
}

void CameraPublisherNode::close() {
    cameraInput_->close();
}

void CameraPublisherNode::nextFrame() {
    cameraInput_->nextFrame();
}

int main(int argc, char** argv) {
    Ros ros_;
    ros_.initialize(argc, argv, gCameraPublisherNode);
    CameraPublisherNode CameraPublisherNode(gCameraNodeFile);
    CameraPublisherNode.getData();
    ros::Rate loop_rate(gPublisherBaudRate);
    while (ros::ok()) {
        CameraPublisherNode.publish();
        ros_.rate();
        loop_rate.sleep();
    }
    return 0;
}
