#include "RadIP.h"

void RadIP::setFileName(const std::string fname) {
	fileName_ = fname;
}

bool RadIP::isOpen() {
	try {
		ROS_INFO("file name is  [%s]",fileName_.c_str());
		bagObj_.open(fileName_, rosbag::bagmode::Read);
        return 1;
	}
	catch(rosbag::BagIOException& errMsg) {
		ROS_INFO("file name is  [%s]",errMsg.what());
		return 0;
	}
}

std::vector<rosbag_creation::RadarMsg::ConstPtr>& RadIP::readRadarData(const std::string topicNameInRosBag) {
	topics_.push_back(topicNameInRosBag);
	ROS_INFO("reading.");
	ROS_INFO("topic name is [%s]",topics_);
	rosbag::View view(bagObj_, rosbag::TopicQuery(topics_));
    for(rosbag::MessageInstance const rosBagConstMsg: rosbag::View(bagObj_)) {
    	
    	rosBagRadarData_  = rosBagConstMsg.instantiate<rosbag_creation::RadarMsg>();
        if (rosBagRadarData_  != NULL) {
        	ROS_INFO("reading..... radar");
        	ROS_INFO("v name is [%d]",rosBagRadarData_->frame);
            radarDataList_.push_back(rosBagRadarData_ );
        }
   
}
 return(radarDataList_);
}


RadIP::~RadIP() {
    bagObj_.close();
}
