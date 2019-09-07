#pragma once

#include "ROSBAGProcessor/radarPolarToCartConvFrame.h"


class PolarToCartConv{
public:
	PolarToCartConv();
	std::vector<int> getCartCordinat(const ROSBAGProcessor::radarPolarToCartConvFrame::ConstPtr& radar_msg);
	double converterHelperFun(double f32_distance);
	double widthToImgColConverter(double f32_distance,double f32_width);

protected:
	int Yaw;
	int ImgCols;
	int ImgRows;
	int LateralOffset; 
	int Radar_Height; 
	int Radar_LateralOffset;
	int CameraToRADARDist;
	double Height;
	double Pitch;  
	double PixelWidth; 
	double PixelHeight;
	double FocalLength; 
};

#endif
