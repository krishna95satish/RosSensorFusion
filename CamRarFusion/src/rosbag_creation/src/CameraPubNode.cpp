#include "CameraPubNode.h"

CameraPubNode::CameraPubNode(const std::string fileName) {
    CamIPObj_.setFileName(fileName);
}

void CameraPubNode::getInputData() {
    
    if(CamIPObj_.isOpen()) {
        tempData_ = CamIPObj_.readCamData(gtopicNameInRosBag);
    }
}
void CameraPubNode::msgPublisher() {
    ros::NodeHandle nodeHandler;
    image_transport::Publisher imagePublisher;
    image_transport::ImageTransport imageTransporter(nodeHandler);
    imagePublisher = imageTransporter.advertise("Krishnas", gQueueSize);
    ROS_INFO("size is [%d],[%d]",getMsgSize(),imgMsgCounter_);
    if(imgMsgCounter_ != getMsgSize()) {
        ROS_INFO("sending");
        ros::Duration(0.5).sleep();
        imagePublisher.publish(tempData_[imgMsgCounter_]);
        cvImgPtr = cv_bridge::toCvCopy(tempData_[imgMsgCounter_], sensor_msgs::image_encodings::BGR8);
        cv::imshow(OPENCV_WINDOW, cvImgPtr->image);
        ROS_INFO ("count is [%d]",imgMsgCounter_);
        goToNextMsg();
    }
    else {
        repeatTransmission();
    }    
}

int CameraPubNode::getMsgSize() {
    return(tempData_.size());
}
void CameraPubNode::goToNextMsg() {
    imgMsgCounter_++;
}

void CameraPubNode::repeatTransmission() {
    imgMsgCounter_ = 0;
}

void CameraPubNode::process() {

}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"CamNode");
    CameraPubNode cameraPubNode(gCameraNodeFile);
    cameraPubNode.getInputData();
    ros::Rate loop_rate(gPubBaudRate);
    while (ros::ok()) {
        cameraPubNode.msgPublisher();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}