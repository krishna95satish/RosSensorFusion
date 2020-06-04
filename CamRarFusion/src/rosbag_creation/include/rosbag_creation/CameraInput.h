    // Copyright 2019 KPIT  [legal/copyright]

#ifndef CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_CAMERAINPUT_H_
#define CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_CAMERAINPUT_H_

#include "Input.h"
#include <string>
#include <vector>

class CameraInput : public Input {
 private:
    CameraInput() {}
    static CameraInput *CameraInputptr;
 protected:
    std::string fileName_;
    rosbag::View view_;
    rosbag::View::iterator iterator_;
    rosbag::Bag bag_;
    std::vector<std::string> topics_{""};
    sensor_msgs::ImagePtr tempCameraFrame_{nullptr};
    sensor_msgs::ImagePtr cameraFrames_;
    bool statusFlag_;

 public:
    void setFileName(const std::string fname);
    bool open();
    void close();
    void nextFrame();
    void read(const std::string topicNameInRosBag);
    bool isBagEmpty();
    sensor_msgs::ImagePtr& getData();
    static CameraInput* newinstance();
    ~CameraInput();
};

#endif  // CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_CAMERAINPUT_H_
