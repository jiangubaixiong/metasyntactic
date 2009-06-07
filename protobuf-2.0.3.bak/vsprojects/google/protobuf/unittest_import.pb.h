// Generated by the protocol buffer compiler.  DO NOT EDIT!

#ifndef PROTOBUF_google_2fprotobuf_2funittest_5fimport_2eproto__INCLUDED
#define PROTOBUF_google_2fprotobuf_2funittest_5fimport_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2000003
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2000003 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>

namespace protobuf_unittest_import {

// Internal implementation detail -- do not call these.
void  protobuf_BuildDesc_google_2fprotobuf_2funittest_5fimport_2eproto();
void protobuf_BuildDesc_google_2fprotobuf_2funittest_5fimport_2eproto_AssignGlobalDescriptors(
    ::google::protobuf::FileDescriptor* file);

class ImportMessage;

enum ImportEnum {
  IMPORT_FOO = 7,
  IMPORT_BAR = 8,
  IMPORT_BAZ = 9
};
const ::google::protobuf::EnumDescriptor* ImportEnum_descriptor();
bool ImportEnum_IsValid(int value);
const ImportEnum ImportEnum_MIN = IMPORT_FOO;
const ImportEnum ImportEnum_MAX = IMPORT_BAZ;

// ===================================================================

class ImportMessage : public ::google::protobuf::Message {
 public:
  ImportMessage();
  virtual ~ImportMessage();
  
  ImportMessage(const ImportMessage& from);
  
  inline ImportMessage& operator=(const ImportMessage& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const ImportMessage& default_instance();
  void Swap(ImportMessage* other);
  
  // implements Message ----------------------------------------------
  
  ImportMessage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ImportMessage& from);
  void MergeFrom(const ImportMessage& from);
  void Clear();
  bool IsInitialized() const;
  int ByteSize() const;
  
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  bool SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SetCachedSize(int size) const { _cached_size_ = size; }
  public:
  
  const ::google::protobuf::Descriptor* GetDescriptor() const;
  const ::google::protobuf::Reflection* GetReflection() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // optional int32 d = 1;
  inline bool has_d() const;
  inline void clear_d();
  inline ::google::protobuf::int32 d() const;
  inline void set_d(::google::protobuf::int32 value);
  
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::int32 d_;
  friend void protobuf_BuildDesc_google_2fprotobuf_2funittest_5fimport_2eproto_AssignGlobalDescriptors(
      const ::google::protobuf::FileDescriptor* file);
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static ImportMessage* default_instance_;
};
// ===================================================================


// ===================================================================


// ===================================================================

// ImportMessage

// optional int32 d = 1;
inline bool ImportMessage::has_d() const {
  return _has_bit(0);
}
inline void ImportMessage::clear_d() {
  d_ = 0;
  _clear_bit(0);
}
inline ::google::protobuf::int32 ImportMessage::d() const {
  return d_;
}
inline void ImportMessage::set_d(::google::protobuf::int32 value) {
  _set_bit(0);
  d_ = value;
}


}  // namespace protobuf_unittest_import
#endif  // PROTOBUF_google_2fprotobuf_2funittest_5fimport_2eproto__INCLUDED
