// Copyright 2019 KPIT

#include "rosbag_creation/Include.h"
#include "rosbag_creation/GlobalConsts.h"
#include "rosbag_creation/RadarInputCsvToRosbag.h"

rosbag_creation::RadarMsg point;
rosbag::Bag bag(gRadarBag, rosbag::bagmode::Write);

RadarInputCsvToRosbag::RadarInputCsvToRosbag() {
  publish_ = node_.advertise<rosbag_creation::RadarMsg>(gRadarTopic, gQueueSize);
}

void RadarInputCsvToRosbag :: initilizeParameter(double range, double angle) {
  range_ = range;
  angle_ = angle;
  write(range_, angle_, frameId_);
}

void RadarInputCsvToRosbag :: read() {
  std::string videoName;
  std::string frame, radarRange, radarAngle, cameraTick, radarTick, lateralDistence, targetID, dataConfidence;
  std::ifstream fin(RadarNodeFile);
  std::string line;
  std::stringstream string(line);
  double range, angle;
  while (getline(fin, line)) {
    std::stringstream string(line);
    std::getline(string, videoName, ',');
    std::getline(string, frame, ',');
    std::getline(string, radarRange, ',');
    std::getline(string, radarAngle, ',');
    std::getline(string, cameraTick, ',');
    std::getline(string, radarTick, ',');
    std::getline(string, lateralDistence, ',');
    std::getline(string, targetID, ',');
    std::getline(string, dataConfidence, ',');
    range = atof(radarRange.c_str());
    angle = atof(radarAngle.c_str());
    frameId_ = atoi(frame.c_str());
    initilizeParameter(range, angle);
  }
}

void RadarInputCsvToRosbag :: write(double range_, double angle_, int frameId) {
  point.radarRange_ = range_;
  point.radarAngle_ = angle_;
  point.frame_ = frameId;
  bag.write(gRadarBagName, ros::Time::now(), point);
  publish_.publish(point);
}

void RadarInputCsvToRosbag :: close() {
  bag.close();
}
