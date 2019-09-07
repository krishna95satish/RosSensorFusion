// Generated by gencpp from file rosbag_creation/RadarMsg.msg
// DO NOT EDIT!


#ifndef ROSBAG_CREATION_MESSAGE_RADARMSG_H
#define ROSBAG_CREATION_MESSAGE_RADARMSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rosbag_creation
{
template <class ContainerAllocator>
struct RadarMsg_
{
  typedef RadarMsg_<ContainerAllocator> Type;

  RadarMsg_()
    : vName()
    , frame(0)
    , radarRange(0.0)
    , radarAngle(0.0)
    , camTick(0)
    , radarTick(0)
    , lateralDist(0.0)
    , targetID(0)
    , dataConfidence(0)  {
    }
  RadarMsg_(const ContainerAllocator& _alloc)
    : vName(_alloc)
    , frame(0)
    , radarRange(0.0)
    , radarAngle(0.0)
    , camTick(0)
    , radarTick(0)
    , lateralDist(0.0)
    , targetID(0)
    , dataConfidence(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _vName_type;
  _vName_type vName;

   typedef int16_t _frame_type;
  _frame_type frame;

   typedef double _radarRange_type;
  _radarRange_type radarRange;

   typedef double _radarAngle_type;
  _radarAngle_type radarAngle;

   typedef int64_t _camTick_type;
  _camTick_type camTick;

   typedef int64_t _radarTick_type;
  _radarTick_type radarTick;

   typedef double _lateralDist_type;
  _lateralDist_type lateralDist;

   typedef int8_t _targetID_type;
  _targetID_type targetID;

   typedef int8_t _dataConfidence_type;
  _dataConfidence_type dataConfidence;





  typedef boost::shared_ptr< ::rosbag_creation::RadarMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosbag_creation::RadarMsg_<ContainerAllocator> const> ConstPtr;

}; // struct RadarMsg_

typedef ::rosbag_creation::RadarMsg_<std::allocator<void> > RadarMsg;

typedef boost::shared_ptr< ::rosbag_creation::RadarMsg > RadarMsgPtr;
typedef boost::shared_ptr< ::rosbag_creation::RadarMsg const> RadarMsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosbag_creation::RadarMsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosbag_creation::RadarMsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rosbag_creation

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'rosbag_creation': ['/home/kpit/CamRarFusion/src/rosbag_creation/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rosbag_creation::RadarMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosbag_creation::RadarMsg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosbag_creation::RadarMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosbag_creation::RadarMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosbag_creation::RadarMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosbag_creation::RadarMsg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosbag_creation::RadarMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f13598e7a6de6888828400fe1afcd644";
  }

  static const char* value(const ::rosbag_creation::RadarMsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf13598e7a6de6888ULL;
  static const uint64_t static_value2 = 0x828400fe1afcd644ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosbag_creation::RadarMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosbag_creation/RadarMsg";
  }

  static const char* value(const ::rosbag_creation::RadarMsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosbag_creation::RadarMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string vName\n"
"int16 frame\n"
"float64 radarRange\n"
"float64 radarAngle\n"
"int64 camTick\n"
"int64 radarTick\n"
"float64 lateralDist\n"
"int8 targetID\n"
"int8 dataConfidence\n"
;
  }

  static const char* value(const ::rosbag_creation::RadarMsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosbag_creation::RadarMsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.vName);
      stream.next(m.frame);
      stream.next(m.radarRange);
      stream.next(m.radarAngle);
      stream.next(m.camTick);
      stream.next(m.radarTick);
      stream.next(m.lateralDist);
      stream.next(m.targetID);
      stream.next(m.dataConfidence);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RadarMsg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosbag_creation::RadarMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosbag_creation::RadarMsg_<ContainerAllocator>& v)
  {
    s << indent << "vName: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.vName);
    s << indent << "frame: ";
    Printer<int16_t>::stream(s, indent + "  ", v.frame);
    s << indent << "radarRange: ";
    Printer<double>::stream(s, indent + "  ", v.radarRange);
    s << indent << "radarAngle: ";
    Printer<double>::stream(s, indent + "  ", v.radarAngle);
    s << indent << "camTick: ";
    Printer<int64_t>::stream(s, indent + "  ", v.camTick);
    s << indent << "radarTick: ";
    Printer<int64_t>::stream(s, indent + "  ", v.radarTick);
    s << indent << "lateralDist: ";
    Printer<double>::stream(s, indent + "  ", v.lateralDist);
    s << indent << "targetID: ";
    Printer<int8_t>::stream(s, indent + "  ", v.targetID);
    s << indent << "dataConfidence: ";
    Printer<int8_t>::stream(s, indent + "  ", v.dataConfidence);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSBAG_CREATION_MESSAGE_RADARMSG_H
