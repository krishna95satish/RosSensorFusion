#include "Node.h"



cv_bridge::CvImagePtr& Node::RosImgToOpenCv(sensor_msgs::ImagePtr& rosImgMsg) {
	cvImgPtr_ = cv_bridge::toCvCopy(rosImgMsg, sensor_msgs::image_encodings::BGR8);
	
		return cvImgPtr_;
}
sensor_msgs::ImagePtr& Node::openCVImgToRosImg()  {
	cv::Mat frame;
	rosImgMsg_ = cv_bridge::CvImage(std_msgs::Header(), "bgr8" , frame).toImageMsg();
	return rosImgMsg_;
}


void Node::getInputData(){}
void Node::msgPublisher(){}
void Node::msgSubscriber(){}
void Node::process(){}
