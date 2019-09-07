#pragma once
#include "Node.h"

class CameraPubNode : public Node{
private:
	std::vector<sensor_msgs::ImagePtr> tempData_;
	int imgMsgCounter_{0};
	cv_bridge::CvImagePtr cvImgPtr;
	const std::string OPENCV_WINDOW = "Image window";

public:
	CameraPubNode(const std::string fileName);
	void getInputData();
	void msgPublisher();
	void repeatTransmission();
	void process();
	int getMsgSize();
	void goToNextMsg();
	~CameraPubNode(){};
};