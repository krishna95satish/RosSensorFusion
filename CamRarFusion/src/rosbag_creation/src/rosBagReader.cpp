#include <rosbag/bag.h>
#include <ros/ros.h>
#include <rosbag/view.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <opencv2/highgui/highgui.hpp>
#include "sensor_msgs/Image.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

static const std::string OPENCV_WINDOW = "Image window";

int main(int argc,char** argv)
{
    rosbag::Bag bag;
   // ros::Time::init();
    bag.open("/home/kpit/CamRarFusion/RosbagInput/cameraBag.bag", rosbag::bagmode::Read);  //add your file path
    //ROS_INFO("entered");
      cv::namedWindow(OPENCV_WINDOW);
    std::vector<std::string> topics;

    ros::init(argc,argv,"videoSubsriber");
	ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
	image_transport::Publisher videoPubObj = it.advertise("finalOut",1000);
    topics.push_back(std::string("/cameraOut"));
    rosbag::View view(bag, rosbag::TopicQuery(topics));
    sensor_msgs::ImagePtr msg;
    for(rosbag::MessageInstance const m: rosbag::View(bag))																	
    {
    	//ROS_INFO("entered for loop");
    	sensor_msgs::ImagePtr s = m.instantiate<sensor_msgs::Image>();

        //std_msgs::String::ConstPtr s = m.instantiate<std_msgs::String>();
        if (s != NULL)
            std::cout << "Image ID="<<s->header.frame_id << std::endl;
        	int count = atoi(s->header.frame_id.c_str());
        	
             cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(s, sensor_msgs::image_encodings::BGR8);

    	if ( (count > 500 ) && cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
    	{
    		ROS_INFO("plotting");
    		ROS_INFO("the count is [%d]",count);
            
    		      	cv::line(cv_ptr->image, cv::Point(89.6615,485.722),\
 					cv::Point(89.6615,485.722), cv::Scalar(255),15);
 					        cv::imshow(OPENCV_WINDOW, cv_ptr->image);
 					        msg  = cv_bridge::CvImage(std_msgs::Header(), "BGR8" , cv_ptr->image).toImageMsg();
 					        ros::Duration(1).sleep();

			videoPubObj.publish(msg);

    	cv::waitKey(10);
    	}
                                                                                                            
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return 1;
    }   

    }

    bag.close();
    return 0;
}
