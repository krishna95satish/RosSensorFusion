#include "RadarDataPubNode.h"

RadarDataPubNode::RadarDataPubNode(const std::string fileName) {
    RadIPObj_.setFileName(fileName);
}

void RadarDataPubNode::getInputData() {
    
    if(RadIPObj_.isOpen()) {
       tempRadarData_ =  RadIPObj_.readRadarData("/RadarDataTopic");
       ROS_INFO ("size is radat [%d]",tempRadarData_[548]->frame);
    }
}
//void RadarDataPubNode::msgPublisher() {
//    ros::NodeHandle nodeHandler;
//    image_transport::Publisher imagePublisher;
//    image_transport::ImageTransport imageTransporter(nodeHandler);
//    imagePublisher = imageTransporter.advertise("Krishnas", gQueueSize);
//    ROS_INFO("size is [%d],[%d]",getMsgSize(),imgMsgCounter_);
//    if(imgMsgCounter_ != getMsgSize()) {
//        ROS_INFO("sending");
//        ros::Duration(0.5).sleep();
//        imagePublisher.publish(tempData_[imgMsgCounter_]);
//        cvImgPtr = cv_bridge::toCvCopy(tempData_[imgMsgCounter_], sensor_msgs::image_encodings::BGR8);
//        cv::imshow(OPENCV_WINDOW, cvImgPtr->image);
//        ROS_INFO ("count is [%d]",imgMsgCounter_);
//        goToNextMsg();
//    }
//    else {
//        repeatTransmission();
//    }    
//}

//int RadarDataPubNode::getMsgSize() {
//    return(tempData_.size());
//}
//void RadarDataPubNode::goToNextMsg() {
//    imgMsgCounter_++;
//}
//
//void RadarDataPubNode::repeatTransmission() {
//    imgMsgCounter_ = 0;
//}
//
//void RadarDataPubNode::process() {
//
//}


int main(int argc, char** argv)
{
    ros::init(argc,argv,"RadarNode");
    RadarDataPubNode cameraPubNode("/home/kpit/CamRarFusion/RosbagInput/radardata.bag");
    cameraPubNode.getInputData();
    ros::Rate loop_rate(gPubBaudRate);
    while (ros::ok()) {
        cameraPubNode.msgPublisher();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
