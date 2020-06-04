
(cl:in-package :asdf)

(defsystem "rosbag_creation-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "RadarMsg" :depends-on ("_package_RadarMsg"))
    (:file "_package_RadarMsg" :depends-on ("_package"))
  ))