// Auto-generated. Do not edit!

// (in-package rosbag_creation.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class RadarMsg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.vName = null;
      this.frame = null;
      this.radarRange = null;
      this.radarAngle = null;
      this.camTick = null;
      this.radarTick = null;
      this.lateralDist = null;
      this.targetID = null;
      this.dataConfidence = null;
    }
    else {
      if (initObj.hasOwnProperty('vName')) {
        this.vName = initObj.vName
      }
      else {
        this.vName = '';
      }
      if (initObj.hasOwnProperty('frame')) {
        this.frame = initObj.frame
      }
      else {
        this.frame = 0;
      }
      if (initObj.hasOwnProperty('radarRange')) {
        this.radarRange = initObj.radarRange
      }
      else {
        this.radarRange = 0.0;
      }
      if (initObj.hasOwnProperty('radarAngle')) {
        this.radarAngle = initObj.radarAngle
      }
      else {
        this.radarAngle = 0.0;
      }
      if (initObj.hasOwnProperty('camTick')) {
        this.camTick = initObj.camTick
      }
      else {
        this.camTick = 0;
      }
      if (initObj.hasOwnProperty('radarTick')) {
        this.radarTick = initObj.radarTick
      }
      else {
        this.radarTick = 0;
      }
      if (initObj.hasOwnProperty('lateralDist')) {
        this.lateralDist = initObj.lateralDist
      }
      else {
        this.lateralDist = 0.0;
      }
      if (initObj.hasOwnProperty('targetID')) {
        this.targetID = initObj.targetID
      }
      else {
        this.targetID = 0;
      }
      if (initObj.hasOwnProperty('dataConfidence')) {
        this.dataConfidence = initObj.dataConfidence
      }
      else {
        this.dataConfidence = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RadarMsg
    // Serialize message field [vName]
    bufferOffset = _serializer.string(obj.vName, buffer, bufferOffset);
    // Serialize message field [frame]
    bufferOffset = _serializer.int16(obj.frame, buffer, bufferOffset);
    // Serialize message field [radarRange]
    bufferOffset = _serializer.float64(obj.radarRange, buffer, bufferOffset);
    // Serialize message field [radarAngle]
    bufferOffset = _serializer.float64(obj.radarAngle, buffer, bufferOffset);
    // Serialize message field [camTick]
    bufferOffset = _serializer.int64(obj.camTick, buffer, bufferOffset);
    // Serialize message field [radarTick]
    bufferOffset = _serializer.int64(obj.radarTick, buffer, bufferOffset);
    // Serialize message field [lateralDist]
    bufferOffset = _serializer.float64(obj.lateralDist, buffer, bufferOffset);
    // Serialize message field [targetID]
    bufferOffset = _serializer.int8(obj.targetID, buffer, bufferOffset);
    // Serialize message field [dataConfidence]
    bufferOffset = _serializer.int8(obj.dataConfidence, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RadarMsg
    let len;
    let data = new RadarMsg(null);
    // Deserialize message field [vName]
    data.vName = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [frame]
    data.frame = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [radarRange]
    data.radarRange = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [radarAngle]
    data.radarAngle = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [camTick]
    data.camTick = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [radarTick]
    data.radarTick = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [lateralDist]
    data.lateralDist = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [targetID]
    data.targetID = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [dataConfidence]
    data.dataConfidence = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.vName.length;
    return length + 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rosbag_creation/RadarMsg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f13598e7a6de6888828400fe1afcd644';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string vName
    int16 frame
    float64 radarRange
    float64 radarAngle
    int64 camTick
    int64 radarTick
    float64 lateralDist
    int8 targetID
    int8 dataConfidence
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RadarMsg(null);
    if (msg.vName !== undefined) {
      resolved.vName = msg.vName;
    }
    else {
      resolved.vName = ''
    }

    if (msg.frame !== undefined) {
      resolved.frame = msg.frame;
    }
    else {
      resolved.frame = 0
    }

    if (msg.radarRange !== undefined) {
      resolved.radarRange = msg.radarRange;
    }
    else {
      resolved.radarRange = 0.0
    }

    if (msg.radarAngle !== undefined) {
      resolved.radarAngle = msg.radarAngle;
    }
    else {
      resolved.radarAngle = 0.0
    }

    if (msg.camTick !== undefined) {
      resolved.camTick = msg.camTick;
    }
    else {
      resolved.camTick = 0
    }

    if (msg.radarTick !== undefined) {
      resolved.radarTick = msg.radarTick;
    }
    else {
      resolved.radarTick = 0
    }

    if (msg.lateralDist !== undefined) {
      resolved.lateralDist = msg.lateralDist;
    }
    else {
      resolved.lateralDist = 0.0
    }

    if (msg.targetID !== undefined) {
      resolved.targetID = msg.targetID;
    }
    else {
      resolved.targetID = 0
    }

    if (msg.dataConfidence !== undefined) {
      resolved.dataConfidence = msg.dataConfidence;
    }
    else {
      resolved.dataConfidence = 0
    }

    return resolved;
    }
};

module.exports = RadarMsg;
