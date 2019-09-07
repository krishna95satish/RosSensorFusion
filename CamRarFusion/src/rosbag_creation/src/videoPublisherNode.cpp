// Copyright 2019 <KPIT>  [legal/copyright]

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <sstream>
#include "std_msgs/String.h"

int main (int argc, char** argv) {

	ros::init(argc,argv,"videoPublisher");
	ros::NodeHandle nh;
	ros::Publisher pubObj;
	image_transport::ImageTransport it(nh);
	image_transport::Publisher videoPubObj = it.advertise("cameraOut",1000);
	cv::VideoCapture cap("/home/kpit/ipv.avi");
	if (!cap.isOpened()) {
		std::cout << "error" << std::endl;
	}
	cv::Mat frame;
	int count = 0;
	sensor_msgs::ImagePtr msg;
	ros::Rate loop_rate(10);
	while (nh.ok()) {
		cap >> frame;
		ROS_INFO("size is [%d],[%d]",frame.rows,frame.cols);
		if(!frame.empty()) {
			msg  = cv_bridge::CvImage(std_msgs::Header(), "bgr8" , frame).toImageMsg();
			std::stringstream ss;
			ss<<count;
			msg->header.frame_id = ss.str();
			ros::Duration(0.1).sleep();
			videoPubObj.publish(msg);
			//ROS_INFO("Publishing [%s]",msg->header.frame_id.c_str());
			//imshow("frame",frame);
			cv::waitKey(10);
			count++;
		}
		else {
			 ROS_INFO(" NO frame available");
		}
		ros::spinOnce();
		loop_rate.sleep();

	}

}
