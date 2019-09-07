#pragma once
#include "Node.h"

class RadarDataPubNode : public Node{
private:
	std::vector<rosbag_creation::RadarMsg::ConstPtr> tempRadarData_;

public:
	RadarDataPubNode(const std::string fileName);
	void getInputData();
	//void msgPublisher();
	//void repeatTransmission();
	//void process();
	//int getMsgSize();
	//void goToNextMsg();
	~RadarDataPubNode(){};
};