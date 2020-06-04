
#include "../include/rosbag_creation/PolarToCartConverter.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(RealWorldWidthToImageColTest,width_1) {
	double f32_distance = 234;
	double f32_width = 678;
	float expectedXCoordinate = 602.69739;
	float XCoordinate;
	PolarToCartConverter PolartocartObj;
	XCoordinate = PolartocartObj.realWorldWidthToImageCol(f32_distance,f32_width);
	ASSERT_FLOAT_EQ(XCoordinate,expectedXCoordinate);
}

TEST(getImageCoordinatesTest,distance) {
	std::vector<int> camCoord_;
	camCoord_.reserve(2);
	camCoord_.push_back(646);
	camCoord_.push_back(479);
	PolarToCartConverter PolartocartObj;
	rosbag_creation::RadarMsg radar_msg;
	radar_msg.radarRange_ =132;
	radar_msg.radarAngle_ = 0.5;
	rosbag_creation::RadarMsg::ConstPtr radMsgPtr(new rosbag_creation::RadarMsg(radar_msg));
	EXPECT_EQ(camCoord_, PolartocartObj.getImageCoordinates(radMsgPtr));
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
