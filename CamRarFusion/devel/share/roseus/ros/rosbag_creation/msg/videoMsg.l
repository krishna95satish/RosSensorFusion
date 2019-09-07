;; Auto-generated. Do not edit!


(when (boundp 'rosbag_creation::videoMsg)
  (if (not (find-package "ROSBAG_CREATION"))
    (make-package "ROSBAG_CREATION"))
  (shadow 'videoMsg (find-package "ROSBAG_CREATION")))
(unless (find-package "ROSBAG_CREATION::VIDEOMSG")
  (make-package "ROSBAG_CREATION::VIDEOMSG"))

(in-package "ROS")
;;//! \htmlinclude videoMsg.msg.html


(defclass rosbag_creation::videoMsg
  :super ros::object
  :slots (_vName _frame _radarRange _radarAngle _camTick _radarTick _lateralDist _targetID _dataConfidence ))

(defmethod rosbag_creation::videoMsg
  (:init
   (&key
    ((:vName __vName) "")
    ((:frame __frame) 0)
    ((:radarRange __radarRange) 0.0)
    ((:radarAngle __radarAngle) 0.0)
    ((:camTick __camTick) 0)
    ((:radarTick __radarTick) 0)
    ((:lateralDist __lateralDist) 0.0)
    ((:targetID __targetID) 0)
    ((:dataConfidence __dataConfidence) 0)
    )
   (send-super :init)
   (setq _vName (string __vName))
   (setq _frame (round __frame))
   (setq _radarRange (float __radarRange))
   (setq _radarAngle (float __radarAngle))
   (setq _camTick (round __camTick))
   (setq _radarTick (round __radarTick))
   (setq _lateralDist (float __lateralDist))
   (setq _targetID (round __targetID))
   (setq _dataConfidence (round __dataConfidence))
   self)
  (:vName
   (&optional __vName)
   (if __vName (setq _vName __vName)) _vName)
  (:frame
   (&optional __frame)
   (if __frame (setq _frame __frame)) _frame)
  (:radarRange
   (&optional __radarRange)
   (if __radarRange (setq _radarRange __radarRange)) _radarRange)
  (:radarAngle
   (&optional __radarAngle)
   (if __radarAngle (setq _radarAngle __radarAngle)) _radarAngle)
  (:camTick
   (&optional __camTick)
   (if __camTick (setq _camTick __camTick)) _camTick)
  (:radarTick
   (&optional __radarTick)
   (if __radarTick (setq _radarTick __radarTick)) _radarTick)
  (:lateralDist
   (&optional __lateralDist)
   (if __lateralDist (setq _lateralDist __lateralDist)) _lateralDist)
  (:targetID
   (&optional __targetID)
   (if __targetID (setq _targetID __targetID)) _targetID)
  (:dataConfidence
   (&optional __dataConfidence)
   (if __dataConfidence (setq _dataConfidence __dataConfidence)) _dataConfidence)
  (:serialization-length
   ()
   (+
    ;; string _vName
    4 (length _vName)
    ;; int16 _frame
    2
    ;; float64 _radarRange
    8
    ;; float64 _radarAngle
    8
    ;; int64 _camTick
    8
    ;; int64 _radarTick
    8
    ;; float64 _lateralDist
    8
    ;; int8 _targetID
    1
    ;; int8 _dataConfidence
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _vName
       (write-long (length _vName) s) (princ _vName s)
     ;; int16 _frame
       (write-word _frame s)
     ;; float64 _radarRange
       (sys::poke _radarRange (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _radarAngle
       (sys::poke _radarAngle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int64 _camTick
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _camTick (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _camTick) (= (length (_camTick . bv)) 2)) ;; bignum
              (write-long (ash (elt (_camTick . bv) 0) 0) s)
              (write-long (ash (elt (_camTick . bv) 1) -1) s))
             ((and (class _camTick) (= (length (_camTick . bv)) 1)) ;; big1
              (write-long (elt (_camTick . bv) 0) s)
              (write-long (if (>= _camTick 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _camTick s)(write-long (if (>= _camTick 0) 0 #xffffffff) s)))
     ;; int64 _radarTick
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _radarTick (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _radarTick) (= (length (_radarTick . bv)) 2)) ;; bignum
              (write-long (ash (elt (_radarTick . bv) 0) 0) s)
              (write-long (ash (elt (_radarTick . bv) 1) -1) s))
             ((and (class _radarTick) (= (length (_radarTick . bv)) 1)) ;; big1
              (write-long (elt (_radarTick . bv) 0) s)
              (write-long (if (>= _radarTick 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _radarTick s)(write-long (if (>= _radarTick 0) 0 #xffffffff) s)))
     ;; float64 _lateralDist
       (sys::poke _lateralDist (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int8 _targetID
       (write-byte _targetID s)
     ;; int8 _dataConfidence
       (write-byte _dataConfidence s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _vName
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _vName (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int16 _frame
     (setq _frame (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float64 _radarRange
     (setq _radarRange (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _radarAngle
     (setq _radarAngle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int64 _camTick
#+(or :alpha :irix6 :x86_64)
      (setf _camTick (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _camTick (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _radarTick
#+(or :alpha :irix6 :x86_64)
      (setf _radarTick (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _radarTick (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _lateralDist
     (setq _lateralDist (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int8 _targetID
     (setq _targetID (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _targetID 127) (setq _targetID (- _targetID 256)))
   ;; int8 _dataConfidence
     (setq _dataConfidence (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _dataConfidence 127) (setq _dataConfidence (- _dataConfidence 256)))
   ;;
   self)
  )

(setf (get rosbag_creation::videoMsg :md5sum-) "f13598e7a6de6888828400fe1afcd644")
(setf (get rosbag_creation::videoMsg :datatype-) "rosbag_creation/videoMsg")
(setf (get rosbag_creation::videoMsg :definition-)
      "string vName
int16 frame
float64 radarRange
float64 radarAngle
int64 camTick
int64 radarTick
float64 lateralDist
int8 targetID
int8 dataConfidence
")



(provide :rosbag_creation/videoMsg "f13598e7a6de6888828400fe1afcd644")


