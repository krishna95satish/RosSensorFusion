// Copyright 2019 KPIT

#include "rosbag_creation/GlobalConsts.h"
#include "rosbag_creation/Include.h"
#include "rosbag_creation/RadarInputCsvToRosbag.h"
#include "rosbag_creation/Ros.h"

int main(int argc, char **argv) {
    Ros ros_;
    ros_.initialize(argc, argv, gArgument);
    OutPut *node;
    RadarInputCsvToRosbag inputCsv;
    node = &inputCsv;
    inputCsv.read();
    node->close();
    return 0;
}
