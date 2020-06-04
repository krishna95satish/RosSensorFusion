# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from rosbag_creation/RadarMsg.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import std_msgs.msg

class RadarMsg(genpy.Message):
  _md5sum = "d2659b67e2e8133a7adad5a93bab2f3a"
  _type = "rosbag_creation/RadarMsg"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """std_msgs/Header header
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
"""
  __slots__ = ['header','videoName_','frame_','radarRange_','radarAngle_','cameraTick_','radarTick_','lateralDistance_','targetID_','dataConfidence_']
  _slot_types = ['std_msgs/Header','string','int16','float64','float64','int64','int64','float64','int8','int8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,videoName_,frame_,radarRange_,radarAngle_,cameraTick_,radarTick_,lateralDistance_,targetID_,dataConfidence_

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(RadarMsg, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.videoName_ is None:
        self.videoName_ = ''
      if self.frame_ is None:
        self.frame_ = 0
      if self.radarRange_ is None:
        self.radarRange_ = 0.
      if self.radarAngle_ is None:
        self.radarAngle_ = 0.
      if self.cameraTick_ is None:
        self.cameraTick_ = 0
      if self.radarTick_ is None:
        self.radarTick_ = 0
      if self.lateralDistance_ is None:
        self.lateralDistance_ = 0.
      if self.targetID_ is None:
        self.targetID_ = 0
      if self.dataConfidence_ is None:
        self.dataConfidence_ = 0
    else:
      self.header = std_msgs.msg.Header()
      self.videoName_ = ''
      self.frame_ = 0
      self.radarRange_ = 0.
      self.radarAngle_ = 0.
      self.cameraTick_ = 0
      self.radarTick_ = 0
      self.lateralDistance_ = 0.
      self.targetID_ = 0
      self.dataConfidence_ = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.videoName_
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_h2d2qd2b().pack(_x.frame_, _x.radarRange_, _x.radarAngle_, _x.cameraTick_, _x.radarTick_, _x.lateralDistance_, _x.targetID_, _x.dataConfidence_))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.videoName_ = str[start:end].decode('utf-8')
      else:
        self.videoName_ = str[start:end]
      _x = self
      start = end
      end += 44
      (_x.frame_, _x.radarRange_, _x.radarAngle_, _x.cameraTick_, _x.radarTick_, _x.lateralDistance_, _x.targetID_, _x.dataConfidence_,) = _get_struct_h2d2qd2b().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.videoName_
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_h2d2qd2b().pack(_x.frame_, _x.radarRange_, _x.radarAngle_, _x.cameraTick_, _x.radarTick_, _x.lateralDistance_, _x.targetID_, _x.dataConfidence_))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.videoName_ = str[start:end].decode('utf-8')
      else:
        self.videoName_ = str[start:end]
      _x = self
      start = end
      end += 44
      (_x.frame_, _x.radarRange_, _x.radarAngle_, _x.cameraTick_, _x.radarTick_, _x.lateralDistance_, _x.targetID_, _x.dataConfidence_,) = _get_struct_h2d2qd2b().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_h2d2qd2b = None
def _get_struct_h2d2qd2b():
    global _struct_h2d2qd2b
    if _struct_h2d2qd2b is None:
        _struct_h2d2qd2b = struct.Struct("<h2d2qd2b")
    return _struct_h2d2qd2b