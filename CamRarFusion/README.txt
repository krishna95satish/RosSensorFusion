Steps to Run the code:

Please note : Input files are already kept in the package for testing,

1.rosrun rosbag_creation RadarInputCsvToRosbag --- run this to generate the Radar bag file
2.rosrun rosbag_creation CameraInputVideoToRosbag --- run this to generate the camera bag file


Please run the below command to launch 3 nodes (Camera, Radar, Fusion):
roslaunch rosbag_creation SensorFusion.launch

Open Rviz to visualize the output using the following comman
---> Rosrun rviz rviz 
---> Select "FusionData" topicname from topiclist to visualize the Output
 	
