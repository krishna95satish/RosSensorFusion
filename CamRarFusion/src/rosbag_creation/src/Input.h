#pragma once
#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include "rosbag_creation/RadarMsg.h"
#include <string>

class Input 
{
 protected:
 	

 public:
 	virtual void setFileName(const std::string fname) = 0;
 	 virtual bool isOpen() = 0;
 	 virtual std::vector<sensor_msgs::ImagePtr>& readCamData(const std::string topicNameInRosBag){};
 	 virtual std::vector<rosbag_creation::RadarMsg::ConstPtr>& readRadarData(const std::string topicNameInRosBag){};
};
