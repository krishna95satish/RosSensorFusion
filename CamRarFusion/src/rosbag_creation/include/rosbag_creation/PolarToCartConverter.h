// Copyright 2019 KPIT  [legal/copyright]
#pragma once
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <cmath>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv_bridge/cv_bridge.h>
#include "rosbag_creation/RadarMsg.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

class PolarToCartConverter {
 protected:
    int yaw_;
    int imgCols_;
    int imgRows_;
    int lateralOffset_;
    int radarheight_;
    int radarLateralOffset_;
    int cameraToRadarDist_;
    double height_;
    double pitch_;
    double pixelWidth_;
    double Pixelheight_;
    double focalLength_;
 public:
    PolarToCartConverter();
    std::vector<int> getImageCoordinates(const rosbag_creation::RadarMsg::ConstPtr& radar_msg);
    double realWorldDistanceToImageRow(double f32_distance);
    double realWorldWidthToImageCol(double f32_distance, double f32_width);
};

