; Auto-generated. Do not edit!


(cl:in-package rosbag_creation-msg)


;//! \htmlinclude RadarMsg.msg.html

(cl:defclass <RadarMsg> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (videoName_
    :reader videoName_
    :initarg :videoName_
    :type cl:string
    :initform "")
   (frame_
    :reader frame_
    :initarg :frame_
    :type cl:fixnum
    :initform 0)
   (radarRange_
    :reader radarRange_
    :initarg :radarRange_
    :type cl:float
    :initform 0.0)
   (radarAngle_
    :reader radarAngle_
    :initarg :radarAngle_
    :type cl:float
    :initform 0.0)
   (cameraTick_
    :reader cameraTick_
    :initarg :cameraTick_
    :type cl:integer
    :initform 0)
   (radarTick_
    :reader radarTick_
    :initarg :radarTick_
    :type cl:integer
    :initform 0)
   (lateralDistance_
    :reader lateralDistance_
    :initarg :lateralDistance_
    :type cl:float
    :initform 0.0)
   (targetID_
    :reader targetID_
    :initarg :targetID_
    :type cl:fixnum
    :initform 0)
   (dataConfidence_
    :reader dataConfidence_
    :initarg :dataConfidence_
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RadarMsg (<RadarMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RadarMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RadarMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosbag_creation-msg:<RadarMsg> is deprecated: use rosbag_creation-msg:RadarMsg instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:header-val is deprecated.  Use rosbag_creation-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'videoName_-val :lambda-list '(m))
(cl:defmethod videoName_-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:videoName_-val is deprecated.  Use rosbag_creation-msg:videoName_ instead.")
  (videoName_ m))

(cl:ensure-generic-function 'frame_-val :lambda-list '(m))
(cl:defmethod frame_-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:frame_-val is deprecated.  Use rosbag_creation-msg:frame_ instead.")
  (frame_ m))

(cl:ensure-generic-function 'radarRange_-val :lambda-list '(m))
(cl:defmethod radarRange_-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:radarRange_-val is deprecated.  Use rosbag_creation-msg:radarRange_ instead.")
  (radarRange_ m))

(cl:ensure-generic-function 'radarAngle_-val :lambda-list '(m))
(cl:defmethod radarAngle_-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:radarAngle_-val is deprecated.  Use rosbag_creation-msg:radarAngle_ instead.")
  (radarAngle_ m))

(cl:ensure-generic-function 'cameraTick_-val :lambda-list '(m))
(cl:defmethod cameraTick_-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:cameraTick_-val is deprecated.  Use rosbag_creation-msg:cameraTick_ instead.")
  (cameraTick_ m))

(cl:ensure-generic-function 'radarTick_-val :lambda-list '(m))
(cl:defmethod radarTick_-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:radarTick_-val is deprecated.  Use rosbag_creation-msg:radarTick_ instead.")
  (radarTick_ m))

(cl:ensure-generic-function 'lateralDistance_-val :lambda-list '(m))
(cl:defmethod lateralDistance_-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:lateralDistance_-val is deprecated.  Use rosbag_creation-msg:lateralDistance_ instead.")
  (lateralDistance_ m))

(cl:ensure-generic-function 'targetID_-val :lambda-list '(m))
(cl:defmethod targetID_-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:targetID_-val is deprecated.  Use rosbag_creation-msg:targetID_ instead.")
  (targetID_ m))

(cl:ensure-generic-function 'dataConfidence_-val :lambda-list '(m))
(cl:defmethod dataConfidence_-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:dataConfidence_-val is deprecated.  Use rosbag_creation-msg:dataConfidence_ instead.")
  (dataConfidence_ m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RadarMsg>) ostream)
  "Serializes a message object of type '<RadarMsg>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'videoName_))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'videoName_))
  (cl:let* ((signed (cl:slot-value msg 'frame_)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'radarRange_))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'radarAngle_))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'cameraTick_)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'radarTick_)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'lateralDistance_))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'targetID_)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'dataConfidence_)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RadarMsg>) istream)
  "Deserializes a message object of type '<RadarMsg>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'videoName_) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'videoName_) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'frame_) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'radarRange_) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'radarAngle_) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cameraTick_) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'radarTick_) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lateralDistance_) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'targetID_) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dataConfidence_) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RadarMsg>)))
  "Returns string type for a message object of type '<RadarMsg>"
  "rosbag_creation/RadarMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RadarMsg)))
  "Returns string type for a message object of type 'RadarMsg"
  "rosbag_creation/RadarMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RadarMsg>)))
  "Returns md5sum for a message object of type '<RadarMsg>"
  "d2659b67e2e8133a7adad5a93bab2f3a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RadarMsg)))
  "Returns md5sum for a message object of type 'RadarMsg"
  "d2659b67e2e8133a7adad5a93bab2f3a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RadarMsg>)))
  "Returns full string definition for message of type '<RadarMsg>"
  (cl:format cl:nil "std_msgs/Header header~%string videoName_~%int16 frame_~%float64 radarRange_~%float64 radarAngle_~%int64 cameraTick_~%int64 radarTick_~%float64 lateralDistance_~%int8 targetID_~%int8 dataConfidence_~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RadarMsg)))
  "Returns full string definition for message of type 'RadarMsg"
  (cl:format cl:nil "std_msgs/Header header~%string videoName_~%int16 frame_~%float64 radarRange_~%float64 radarAngle_~%int64 cameraTick_~%int64 radarTick_~%float64 lateralDistance_~%int8 targetID_~%int8 dataConfidence_~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RadarMsg>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'videoName_))
     2
     8
     8
     8
     8
     8
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RadarMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'RadarMsg
    (cl:cons ':header (header msg))
    (cl:cons ':videoName_ (videoName_ msg))
    (cl:cons ':frame_ (frame_ msg))
    (cl:cons ':radarRange_ (radarRange_ msg))
    (cl:cons ':radarAngle_ (radarAngle_ msg))
    (cl:cons ':cameraTick_ (cameraTick_ msg))
    (cl:cons ':radarTick_ (radarTick_ msg))
    (cl:cons ':lateralDistance_ (lateralDistance_ msg))
    (cl:cons ':targetID_ (targetID_ msg))
    (cl:cons ':dataConfidence_ (dataConfidence_ msg))
))
