// Copyright 2019 KPIT

#ifndef CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_RADARINPUTCSVTOROSBAG_H_
#define CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_RADARINPUTCSVTOROSBAG_H_

#include <rosbag_creation/GlobalConsts.h>
#include "rosbag_creation/RadarMsg.h"
#include "OutPut.h"

class RadarInputCsvToRosbag : public OutPut {
 private:
  double range_, angle_;
  double frameId_;

 public:
  RadarInputCsvToRosbag();
  void read();
  void initilizeParameter(double, double);
  void write(double, double, int);
  void close();
};

#endif  // CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_RADARINPUTCSVTOROSBAG_H_
