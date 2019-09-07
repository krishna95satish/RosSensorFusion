; Auto-generated. Do not edit!


(cl:in-package rosbag_creation-msg)


;//! \htmlinclude RadarMsg.msg.html

(cl:defclass <RadarMsg> (roslisp-msg-protocol:ros-message)
  ((vName
    :reader vName
    :initarg :vName
    :type cl:string
    :initform "")
   (frame
    :reader frame
    :initarg :frame
    :type cl:fixnum
    :initform 0)
   (radarRange
    :reader radarRange
    :initarg :radarRange
    :type cl:float
    :initform 0.0)
   (radarAngle
    :reader radarAngle
    :initarg :radarAngle
    :type cl:float
    :initform 0.0)
   (camTick
    :reader camTick
    :initarg :camTick
    :type cl:integer
    :initform 0)
   (radarTick
    :reader radarTick
    :initarg :radarTick
    :type cl:integer
    :initform 0)
   (lateralDist
    :reader lateralDist
    :initarg :lateralDist
    :type cl:float
    :initform 0.0)
   (targetID
    :reader targetID
    :initarg :targetID
    :type cl:fixnum
    :initform 0)
   (dataConfidence
    :reader dataConfidence
    :initarg :dataConfidence
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RadarMsg (<RadarMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RadarMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RadarMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosbag_creation-msg:<RadarMsg> is deprecated: use rosbag_creation-msg:RadarMsg instead.")))

(cl:ensure-generic-function 'vName-val :lambda-list '(m))
(cl:defmethod vName-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:vName-val is deprecated.  Use rosbag_creation-msg:vName instead.")
  (vName m))

(cl:ensure-generic-function 'frame-val :lambda-list '(m))
(cl:defmethod frame-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:frame-val is deprecated.  Use rosbag_creation-msg:frame instead.")
  (frame m))

(cl:ensure-generic-function 'radarRange-val :lambda-list '(m))
(cl:defmethod radarRange-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:radarRange-val is deprecated.  Use rosbag_creation-msg:radarRange instead.")
  (radarRange m))

(cl:ensure-generic-function 'radarAngle-val :lambda-list '(m))
(cl:defmethod radarAngle-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:radarAngle-val is deprecated.  Use rosbag_creation-msg:radarAngle instead.")
  (radarAngle m))

(cl:ensure-generic-function 'camTick-val :lambda-list '(m))
(cl:defmethod camTick-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:camTick-val is deprecated.  Use rosbag_creation-msg:camTick instead.")
  (camTick m))

(cl:ensure-generic-function 'radarTick-val :lambda-list '(m))
(cl:defmethod radarTick-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:radarTick-val is deprecated.  Use rosbag_creation-msg:radarTick instead.")
  (radarTick m))

(cl:ensure-generic-function 'lateralDist-val :lambda-list '(m))
(cl:defmethod lateralDist-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:lateralDist-val is deprecated.  Use rosbag_creation-msg:lateralDist instead.")
  (lateralDist m))

(cl:ensure-generic-function 'targetID-val :lambda-list '(m))
(cl:defmethod targetID-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:targetID-val is deprecated.  Use rosbag_creation-msg:targetID instead.")
  (targetID m))

(cl:ensure-generic-function 'dataConfidence-val :lambda-list '(m))
(cl:defmethod dataConfidence-val ((m <RadarMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbag_creation-msg:dataConfidence-val is deprecated.  Use rosbag_creation-msg:dataConfidence instead.")
  (dataConfidence m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RadarMsg>) ostream)
  "Serializes a message object of type '<RadarMsg>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'vName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'vName))
  (cl:let* ((signed (cl:slot-value msg 'frame)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'radarRange))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'radarAngle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'camTick)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'radarTick)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'lateralDist))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'targetID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'dataConfidence)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RadarMsg>) istream)
  "Deserializes a message object of type '<RadarMsg>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vName) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'vName) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'frame) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'radarRange) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'radarAngle) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'camTick) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'radarTick) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lateralDist) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'targetID) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dataConfidence) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
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
  "f13598e7a6de6888828400fe1afcd644")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RadarMsg)))
  "Returns md5sum for a message object of type 'RadarMsg"
  "f13598e7a6de6888828400fe1afcd644")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RadarMsg>)))
  "Returns full string definition for message of type '<RadarMsg>"
  (cl:format cl:nil "string vName~%int16 frame~%float64 radarRange~%float64 radarAngle~%int64 camTick~%int64 radarTick~%float64 lateralDist~%int8 targetID~%int8 dataConfidence~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RadarMsg)))
  "Returns full string definition for message of type 'RadarMsg"
  (cl:format cl:nil "string vName~%int16 frame~%float64 radarRange~%float64 radarAngle~%int64 camTick~%int64 radarTick~%float64 lateralDist~%int8 targetID~%int8 dataConfidence~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RadarMsg>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'vName))
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
    (cl:cons ':vName (vName msg))
    (cl:cons ':frame (frame msg))
    (cl:cons ':radarRange (radarRange msg))
    (cl:cons ':radarAngle (radarAngle msg))
    (cl:cons ':camTick (camTick msg))
    (cl:cons ':radarTick (radarTick msg))
    (cl:cons ':lateralDist (lateralDist msg))
    (cl:cons ':targetID (targetID msg))
    (cl:cons ':dataConfidence (dataConfidence msg))
))
