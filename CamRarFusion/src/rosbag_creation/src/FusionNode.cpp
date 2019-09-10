// Copyright 2019 KPIT  [legal/copyright]
#include "rosbag_creation/FusionNode.h"


FusionNode::FusionNode():imageTransporter_(nodeHandler_){
  imagePublisher_ = imageTransporter_.advertise("FusionData", 10);
}

void FusionNode::msgSubscriber() {
    ROS_INFO("subscribe.....");
    imageTransporterSub_ = imageTransporter_.subscribe("CamMsg", 1000, &FusionNode::imageCallback,this);
    msgSubscriber_ = nodeHandler_.subscribe("RadarMsg", 1000, &FusionNode::radarCallback,this);
}

void FusionNode::imageCallback(const sensor_msgs::Image::ConstPtr& cameraMsg) {
    imageRecivedFlag_ = true;
    imageID_ = cameraMsg->header.frame_id;
    ROS_INFO("camera image id is  [%d]",atoi(imageID_.c_str()));
    processedImgData_= RosImgToOpenCv(cameraMsg);
}

void FusionNode::plotting(const rosbag_creation::RadarMsg::ConstPtr& radar_msg) {
  std::vector<int> cartCoOrdinates;
        cartCoOrdinates = polarToCartConverter_.getImageCoordinates(radar_msg);
      ROS_INFO("the co ords are [%d],[%d]",cartCoOrdinates[0],cartCoOrdinates[1]);
  //if(radarID_ == atoi(imageID_.c_str())){
      cartCoOrdinates = polarToCartConverter_.getImageCoordinates(radar_msg);
      ROS_INFO("the co ords are [%d],[%d]",cartCoOrdinates[0],cartCoOrdinates[1]);
      cv::circle(processedImgData_->image, cv::Point2i\
        (cartCoOrdinates[0],cartCoOrdinates[1]), 4, cv::Scalar(0,0,255), 4, 3);
      msgPublisher();
}

void FusionNode::radarCallback(const rosbag_creation::RadarMsg::ConstPtr& radarMsg) {
    radarRecivedFlag_ = true;
    ROS_INFO("radar_callback ");
    radarID_ = radarMsg->frame;
    ROS_INFO("the radar frame  is [%d]",radarID_);
    plotting(radarMsg);
}



int FusionNode::getMsgSize() {

}
void FusionNode::goToNextMsg() {

}
void FusionNode::msgPublisher(){
    ROS_INFO("publishing the final out ");
    imagePublisher_.publish(processedImgData_->toImageMsg());
}
void FusionNode::repeatTransmission(){

}
int main(int argc, char** argv) {
    ros::init(argc, argv, "FusionNode");
    FusionNode fusionNode;
    fusionNode.msgSubscriber();
    ros::spin();
    return 0;
}