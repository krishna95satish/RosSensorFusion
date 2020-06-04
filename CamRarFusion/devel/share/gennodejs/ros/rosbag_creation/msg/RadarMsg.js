// Auto-generated. Do not edit!

// (in-package rosbag_creation.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RadarMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.videoName_ = null;
      this.frame_ = null;
      this.radarRange_ = null;
      this.radarAngle_ = null;
      this.cameraTick_ = null;
      this.radarTick_ = null;
      this.lateralDistance_ = null;
      this.targetID_ = null;
      this.dataConfidence_ = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('videoName_')) {
        this.videoName_ = initObj.videoName_
      }
      else {
        this.videoName_ = '';
      }
      if (initObj.hasOwnProperty('frame_')) {
        this.frame_ = initObj.frame_
      }
      else {
        this.frame_ = 0;
      }
      if (initObj.hasOwnProperty('radarRange_')) {
        this.radarRange_ = initObj.radarRange_
      }
      else {
        this.radarRange_ = 0.0;
      }
      if (initObj.hasOwnProperty('radarAngle_')) {
        this.radarAngle_ = initObj.radarAngle_
      }
      else {
        this.radarAngle_ = 0.0;
      }
      if (initObj.hasOwnProperty('cameraTick_')) {
        this.cameraTick_ = initObj.cameraTick_
      }
      else {
        this.cameraTick_ = 0;
      }
      if (initObj.hasOwnProperty('radarTick_')) {
        this.radarTick_ = initObj.radarTick_
      }
      else {
        this.radarTick_ = 0;
      }
      if (initObj.hasOwnProperty('lateralDistance_')) {
        this.lateralDistance_ = initObj.lateralDistance_
      }
      else {
        this.lateralDistance_ = 0.0;
      }
      if (initObj.hasOwnProperty('targetID_')) {
        this.targetID_ = initObj.targetID_
      }
      else {
        this.targetID_ = 0;
      }
      if (initObj.hasOwnProperty('dataConfidence_')) {
        this.dataConfidence_ = initObj.dataConfidence_
      }
      else {
        this.dataConfidence_ = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RadarMsg
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [videoName_]
    bufferOffset = _serializer.string(obj.videoName_, buffer, bufferOffset);
    // Serialize message field [frame_]
    bufferOffset = _serializer.int16(obj.frame_, buffer, bufferOffset);
    // Serialize message field [radarRange_]
    bufferOffset = _serializer.float64(obj.radarRange_, buffer, bufferOffset);
    // Serialize message field [radarAngle_]
    bufferOffset = _serializer.float64(obj.radarAngle_, buffer, bufferOffset);
    // Serialize message field [cameraTick_]
    bufferOffset = _serializer.int64(obj.cameraTick_, buffer, bufferOffset);
    // Serialize message field [radarTick_]
    bufferOffset = _serializer.int64(obj.radarTick_, buffer, bufferOffset);
    // Serialize message field [lateralDistance_]
    bufferOffset = _serializer.float64(obj.lateralDistance_, buffer, bufferOffset);
    // Serialize message field [targetID_]
    bufferOffset = _serializer.int8(obj.targetID_, buffer, bufferOffset);
    // Serialize message field [dataConfidence_]
    bufferOffset = _serializer.int8(obj.dataConfidence_, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RadarMsg
    let len;
    let data = new RadarMsg(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [videoName_]
    data.videoName_ = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [frame_]
    data.frame_ = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [radarRange_]
    data.radarRange_ = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [radarAngle_]
    data.radarAngle_ = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cameraTick_]
    data.cameraTick_ = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [radarTick_]
    data.radarTick_ = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [lateralDistance_]
    data.lateralDistance_ = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [targetID_]
    data.targetID_ = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [dataConfidence_]
    data.dataConfidence_ = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.videoName_.length;
    return length + 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rosbag_creation/RadarMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd2659b67e2e8133a7adad5a93bab2f3a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RadarMsg(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.videoName_ !== undefined) {
      resolved.videoName_ = msg.videoName_;
    }
    else {
      resolved.videoName_ = ''
    }

    if (msg.frame_ !== undefined) {
      resolved.frame_ = msg.frame_;
    }
    else {
      resolved.frame_ = 0
    }

    if (msg.radarRange_ !== undefined) {
      resolved.radarRange_ = msg.radarRange_;
    }
    else {
      resolved.radarRange_ = 0.0
    }

    if (msg.radarAngle_ !== undefined) {
      resolved.radarAngle_ = msg.radarAngle_;
    }
    else {
      resolved.radarAngle_ = 0.0
    }

    if (msg.cameraTick_ !== undefined) {
      resolved.cameraTick_ = msg.cameraTick_;
    }
    else {
      resolved.cameraTick_ = 0
    }

    if (msg.radarTick_ !== undefined) {
      resolved.radarTick_ = msg.radarTick_;
    }
    else {
      resolved.radarTick_ = 0
    }

    if (msg.lateralDistance_ !== undefined) {
      resolved.lateralDistance_ = msg.lateralDistance_;
    }
    else {
      resolved.lateralDistance_ = 0.0
    }

    if (msg.targetID_ !== undefined) {
      resolved.targetID_ = msg.targetID_;
    }
    else {
      resolved.targetID_ = 0
    }

    if (msg.dataConfidence_ !== undefined) {
      resolved.dataConfidence_ = msg.dataConfidence_;
    }
    else {
      resolved.dataConfidence_ = 0
    }

    return resolved;
    }
};

module.exports = RadarMsg;
