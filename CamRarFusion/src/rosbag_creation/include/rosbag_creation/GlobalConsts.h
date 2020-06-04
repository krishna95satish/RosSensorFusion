// Copyright 2019 KPIT  [legal/copyright]

#ifndef CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_GLOBALCONSTS_H_
#define CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_GLOBALCONSTS_H_

#include "Include.h"
const int gCount = 1;
const int gImagerate = 10;
const int gFrameReset = 0;
const int gQueueSize = 1000;
const int gDebugMode = 1;
const int gPublisherBaudRate  = 30;
const int gRadarplotconstant = -1;
const int gsleepduration = 5;

constexpr char const* gCanFileName = "../CANDATAINPUT.csv";
constexpr char const* gPubTopicName = "CanDataTopic";
constexpr char const* gRadarPublisherNode = "RadarNode";
constexpr char const* gCameraPublisherNode = "CamNode";
constexpr char const* gFusionNode = "FusionNode";
constexpr char const* gRadarMsgname = "RadarMsg";
constexpr char const* gCameraMsgname = "CamMsg";
constexpr char const* gFusionMsgname = "FusionData";
constexpr char const* gCameraNodeName = "CameraNode";
constexpr char const* gRadarBag = "ROSBagFiles/Radar.bag";
constexpr char const* gCameraBag = "ROSBagFiles/Frames.bag";
constexpr char const* gtopicNameInRosBag = "/frame";
constexpr char const* gRadarTopic = "/radar";
constexpr char const* gRadarBagName = "radar";
constexpr char const* gCameraBagName = "frame";
constexpr char const* gArgument = "readCSV";
constexpr char const* gFrameArgument = "frames";
constexpr char const* gCameraTopicName = "CamData";
constexpr char const* gColorStanderd = "bgr8";
#define gCameraNodeFile "../CamRarFusion/ROSBagFiles/Frames.bag"
#define gRadarNodeFile "../CamRarFusion/ROSBagFiles/Radar.bag"
constexpr char const* CameraNodeFile = "../CamRarFusion/InputFiles/Camera.avi";
constexpr char const* RadarNodeFile = "../CamRarFusion/InputFiles/CSVdata.csv";
constexpr char const* gCamPubTopicName = "CamDataTopicOut";
constexpr char const* gRadarTopicname = "/RadarData";

#endif  // CAMRARFUSION_SRC_ROSBAG_CREATION_INCLUDE_ROSBAG_CREATION_GLOBALCONSTS_H_
