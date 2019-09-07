#include "PolarToCartConv.h"

PolarToCartConv::PolarToCartConv(){
	Height = 1.46;
	Pitch = -0.023 ; 
	Yaw = 0 ; 
	PixelWidth = pow(3.75,-6);
	PixelHeight =pow(3.75,-6);
	ImgCols = 1280;
	ImgRows = 960;
	FocalLength = pow(6,-3);
	LateralOffset = 0;
	Radar_Height = 0;
	Radar_LateralOffset = 0;
	CameraToRADARDist = 1.65; 
}
    
std::vector<int> PolarToCartConv::getCartCordinat(const ROSBAGProcessor::radarPolarToCartConvFrame::ConstPtr& radar_msg){
	std::vector<int> camCoord_;
	int u32_CameraHeight =Height;
	int  u32_RadarHeight = Radar_Height;
	double  u32_RadarRange = radar_msg->radarRange;
	int  u32_CameraTORadarDistance = CameraToRADARDist;
	double  f32_RadarAngle = radar_msg->radarAngle;
	f32_RadarAngle = -f32_RadarAngle;
	int  s32_CameraOffset = LateralOffset;
	int  s32_RadarOffset = Radar_LateralOffset;
	int  f32_CameraYaw_rad =Yaw;
	double f32_distanceObj;
	double u32_RadarRangeLong = u32_RadarRange * cos(f32_RadarAngle);

	double f32_distanceObj_temp = ((u32_CameraTORadarDistance + u32_RadarRangeLong) / cos(f32_CameraYaw_rad))+                    sin(f32_CameraYaw_rad)*((u32_CameraTORadarDistance + u32_RadarRangeLong) * tan(f32_CameraYaw_rad) 
	- (u32_RadarRangeLong * tan(f32_RadarAngle) + s32_CameraOffset - s32_RadarOffset));

	if (u32_RadarHeight == 0)
		f32_distanceObj = f32_distanceObj_temp;
	else
		f32_distanceObj = f32_distanceObj_temp * u32_CameraHeight / (u32_CameraHeight - u32_RadarHeight);

	double f32_widthObj = -cos(f32_CameraYaw_rad) * ((u32_CameraTORadarDistance + u32_RadarRangeLong) * tan(f32_CameraYaw_rad) -
	    (u32_RadarRangeLong * tan(f32_RadarAngle) + s32_CameraOffset - s32_RadarOffset));

	long double u32YCord = converterHelperFun(f32_distanceObj);
	long double u32XCord = widthToImgColConverter(f32_distanceObj_temp, f32_widthObj);

	camCoord_.reserve(2);
	camCoord_.push_back(u32XCord);
	camCoord_.push_back(u32YCord);
	return camCoord_;
}

double PolarToCartConv::converterHelperFun(double f32_distance){
	int u32_SensorRows = ImgRows;
	double s32CameraHeight = Height;
	double f32_CameraPitch_rad = Pitch;
	double f32_CameraFocusLength =FocalLength;
	double f32_SensorPixelHeight = PixelHeight;
	double f32_ImageRow = u32_SensorRows / 2 + (s32CameraHeight * cos(f32_CameraPitch_rad) + f32_distance * sin(f32_CameraPitch_rad)) / (
		           f32_distance * cos(f32_CameraPitch_rad) - s32CameraHeight * 
				   sin(f32_CameraPitch_rad)) * f32_CameraFocusLength / f32_SensorPixelHeight;
	return f32_ImageRow;
}


double PolarToCartConv::widthToImgColConverter(double f32_distance,double f32_width){
	int u32_SensorCols = ImgCols;
	double s32CameraHeight = Height;
	double f32_CameraFocusLength = FocalLength;
	double f32_SensorPixelWidth = PixelWidth;
	double f32_width_Pixel = ((f32_CameraFocusLength * f32_width) / sqrt(float(s32CameraHeight * 
							s32CameraHeight)+ float(f32_distance * f32_distance))) / f32_SensorPixelWidth;
	double f32_ImageCol = float((float(u32_SensorCols / 2) - f32_width_Pixel));
	return (f32_ImageCol);
}



