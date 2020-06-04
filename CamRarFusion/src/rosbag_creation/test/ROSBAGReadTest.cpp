
#include "../include/rosbag_creation/RadarInput.h"
#include "../include/rosbag_creation/CameraInput.h"
#include <gtest/gtest.h>

TEST(readRadarData, positive) {
	RadarInput readerobj;
	bool fopenstatus_;
	fopenstatus_ = readerobj.open();
	EXPECT_EQ(fopenstatus_, 0);
}

TEST(readCameraData, positive) {
	CameraInput readerobj;
	bool fopenstatus_;
	fopenstatus_ = readerobj.open();
	EXPECT_EQ(fopenstatus_, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
