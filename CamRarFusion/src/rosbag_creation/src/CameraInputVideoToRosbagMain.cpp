// Copyright 2019 KPIT  [legal/copyright]

#include "rosbag_creation/GlobalConsts.h"
#include "rosbag_creation/Include.h"
#include "rosbag_creation/CameraInputVideoToRosbag.h"
#include "rosbag_creation/Ros.h"

int main(int argc, char **argv) {
    Ros ros_;
    ros_.initialize(argc, argv, gFrameArgument);
    /*OutPut *node;
    CameraInputVideoToRosbag input;
    node = &input;
    node->close();
    input.close();*/
    CameraInputVideoToRosbag *obj = CameraInputVideoToRosbag::instancecreation();
    obj->close();
    ros_.spin();
    return 0;
}
