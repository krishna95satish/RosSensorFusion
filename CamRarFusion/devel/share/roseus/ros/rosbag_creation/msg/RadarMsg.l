;; Auto-generated. Do not edit!


(when (boundp 'rosbag_creation::RadarMsg)
  (if (not (find-package "ROSBAG_CREATION"))
    (make-package "ROSBAG_CREATION"))
  (shadow 'RadarMsg (find-package "ROSBAG_CREATION")))
(unless (find-package "ROSBAG_CREATION::RADARMSG")
  (make-package "ROSBAG_CREATION::RADARMSG"))

(in-package "ROS")
;;//! \htmlinclude RadarMsg.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass rosbag_creation::RadarMsg
  :super ros::object
  :slots (_header _videoName_ _frame_ _radarRange_ _radarAngle_ _cameraTick_ _radarTick_ _lateralDistance_ _targetID_ _dataConfidence_ ))

(defmethod rosbag_creation::RadarMsg
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:videoName_ __videoName_) "")
    ((:frame_ __frame_) 0)
    ((:radarRange_ __radarRange_) 0.0)
    ((:radarAngle_ __radarAngle_) 0.0)
    ((:cameraTick_ __cameraTick_) 0)
    ((:radarTick_ __radarTick_) 0)
    ((:lateralDistance_ __lateralDistance_) 0.0)
    ((:targetID_ __targetID_) 0)
    ((:dataConfidence_ __dataConfidence_) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _videoName_ (string __videoName_))
   (setq _frame_ (round __frame_))
   (setq _radarRange_ (float __radarRange_))
   (setq _radarAngle_ (float __radarAngle_))
   (setq _cameraTick_ (round __cameraTick_))
   (setq _radarTick_ (round __radarTick_))
   (setq _lateralDistance_ (float __lateralDistance_))
   (setq _targetID_ (round __targetID_))
   (setq _dataConfidence_ (round __dataConfidence_))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:videoName_
   (&optional __videoName_)
   (if __videoName_ (setq _videoName_ __videoName_)) _videoName_)
  (:frame_
   (&optional __frame_)
   (if __frame_ (setq _frame_ __frame_)) _frame_)
  (:radarRange_
   (&optional __radarRange_)
   (if __radarRange_ (setq _radarRange_ __radarRange_)) _radarRange_)
  (:radarAngle_
   (&optional __radarAngle_)
   (if __radarAngle_ (setq _radarAngle_ __radarAngle_)) _radarAngle_)
  (:cameraTick_
   (&optional __cameraTick_)
   (if __cameraTick_ (setq _cameraTick_ __cameraTick_)) _cameraTick_)
  (:radarTick_
   (&optional __radarTick_)
   (if __radarTick_ (setq _radarTick_ __radarTick_)) _radarTick_)
  (:lateralDistance_
   (&optional __lateralDistance_)
   (if __lateralDistance_ (setq _lateralDistance_ __lateralDistance_)) _lateralDistance_)
  (:targetID_
   (&optional __targetID_)
   (if __targetID_ (setq _targetID_ __targetID_)) _targetID_)
  (:dataConfidence_
   (&optional __dataConfidence_)
   (if __dataConfidence_ (setq _dataConfidence_ __dataConfidence_)) _dataConfidence_)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _videoName_
    4 (length _videoName_)
    ;; int16 _frame_
    2
    ;; float64 _radarRange_
    8
    ;; float64 _radarAngle_
    8
    ;; int64 _cameraTick_
    8
    ;; int64 _radarTick_
    8
    ;; float64 _lateralDistance_
    8
    ;; int8 _targetID_
    1
    ;; int8 _dataConfidence_
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _videoName_
       (write-long (length _videoName_) s) (princ _videoName_ s)
     ;; int16 _frame_
       (write-word _frame_ s)
     ;; float64 _radarRange_
       (sys::poke _radarRange_ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _radarAngle_
       (sys::poke _radarAngle_ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _cameraTick_
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _cameraTick_ (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _cameraTick_) (= (length (_cameraTick_ . bv)) 2)) ;; bignum
              (write-long (ash (elt (_cameraTick_ . bv) 0) 0) s)
              (write-long (ash (elt (_cameraTick_ . bv) 1) -1) s))
             ((and (class _cameraTick_) (= (length (_cameraTick_ . bv)) 1)) ;; big1
              (write-long (elt (_cameraTick_ . bv) 0) s)
              (write-long (if (>= _cameraTick_ 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _cameraTick_ s)(write-long (if (>= _cameraTick_ 0) 0 #xffffffff) s)))
     ;; int64 _radarTick_
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _radarTick_ (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _radarTick_) (= (length (_radarTick_ . bv)) 2)) ;; bignum
              (write-long (ash (elt (_radarTick_ . bv) 0) 0) s)
              (write-long (ash (elt (_radarTick_ . bv) 1) -1) s))
             ((and (class _radarTick_) (= (length (_radarTick_ . bv)) 1)) ;; big1
              (write-long (elt (_radarTick_ . bv) 0) s)
              (write-long (if (>= _radarTick_ 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _radarTick_ s)(write-long (if (>= _radarTick_ 0) 0 #xffffffff) s)))
     ;; float64 _lateralDistance_
       (sys::poke _lateralDistance_ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int8 _targetID_
       (write-byte _targetID_ s)
     ;; int8 _dataConfidence_
       (write-byte _dataConfidence_ s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _videoName_
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _videoName_ (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int16 _frame_
     (setq _frame_ (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float64 _radarRange_
     (setq _radarRange_ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _radarAngle_
     (setq _radarAngle_ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _cameraTick_
#+(or :alpha :irix6 :x86_64)
      (setf _cameraTick_ (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _cameraTick_ (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _radarTick_
#+(or :alpha :irix6 :x86_64)
      (setf _radarTick_ (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _radarTick_ (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _lateralDistance_
     (setq _lateralDistance_ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int8 _targetID_
     (setq _targetID_ (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _targetID_ 127) (setq _targetID_ (- _targetID_ 256)))
   ;; int8 _dataConfidence_
     (setq _dataConfidence_ (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _dataConfidence_ 127) (setq _dataConfidence_ (- _dataConfidence_ 256)))
   ;;
   self)
  )

(setf (get rosbag_creation::RadarMsg :md5sum-) "d2659b67e2e8133a7adad5a93bab2f3a")
(setf (get rosbag_creation::RadarMsg :datatype-) "rosbag_creation/RadarMsg")
(setf (get rosbag_creation::RadarMsg :definition-)
      "std_msgs/Header header
string videoName_
int16 frame_
float64 radarRange_
float64 radarAngle_
int64 cameraTick_
int64 radarTick_
float64 lateralDistance_
int8 targetID_
int8 dataConfidence_

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :rosbag_creation/RadarMsg "d2659b67e2e8133a7adad5a93bab2f3a")


