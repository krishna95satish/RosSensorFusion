// Copyright 2019 KPIT  [legal/copyright]

#include "rosbag_creation/CameraInput.h"

void CameraInput::setFileName(const std::string fname) {
    fileName_ = fname;
}

CameraInput* CameraInput::CameraInputptr = NULL;

bool CameraInput::open() {
    try {
        bag_.open(fileName_, rosbag::bagmode::Read);
        statusFlag_ = true;
    }
    catch(rosbag::BagIOException& errMsg) {
        ROS_INFO("Error is :  [%s]", errMsg.what());
        statusFlag_ = false;
    }
    return statusFlag_;
}

CameraInput* CameraInput::newinstance() {
    if (CameraInputptr == NULL) {
        CameraInputptr = new CameraInput;
    }
    return CameraInputptr;
}

void CameraInput::read(const std::string topicNameInRosBag) {
    view_.addQuery(bag_, rosbag::TopicQuery(topicNameInRosBag));
    iterator_ = view_.begin();
}

sensor_msgs::ImagePtr& CameraInput::getData() {
    rosbag::MessageInstance const messageInstance = *iterator_;
    cameraFrames_ = messageInstance.instantiate<sensor_msgs::Image>();
    if (cameraFrames_) {
        return(cameraFrames_);
    }
}

void CameraInput::nextFrame() {
    if (++iterator_ == view_.end()) {
        iterator_ = view_.begin();
    } else {
        ++iterator_;
    }
}

void CameraInput::close() {
    bag_.close();
}

CameraInput::~CameraInput() {
    delete(CameraInputptr);
}
