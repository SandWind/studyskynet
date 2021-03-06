// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: moblie.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_moblie_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_moblie_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015007 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "apps.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_moblie_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_moblie_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_moblie_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_moblie_2eproto_metadata_getter(int index);
namespace mycell {
namespace moblie {
class moblie;
struct moblieDefaultTypeInternal;
extern moblieDefaultTypeInternal _moblie_default_instance_;
}  // namespace moblie
}  // namespace mycell
PROTOBUF_NAMESPACE_OPEN
template<> ::mycell::moblie::moblie* Arena::CreateMaybeMessage<::mycell::moblie::moblie>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mycell {
namespace moblie {

enum Brand : int {
  unknown = 0,
  huawei = 1,
  xiaomi = 2,
  oppo = 3,
  vivo = 4,
  apple = 5,
  Brand_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Brand_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Brand_IsValid(int value);
constexpr Brand Brand_MIN = unknown;
constexpr Brand Brand_MAX = apple;
constexpr int Brand_ARRAYSIZE = Brand_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Brand_descriptor();
template<typename T>
inline const std::string& Brand_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Brand>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Brand_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Brand_descriptor(), enum_t_value);
}
inline bool Brand_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Brand* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Brand>(
    Brand_descriptor(), name, value);
}
// ===================================================================

class moblie PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mycell.moblie.moblie) */ {
 public:
  inline moblie() : moblie(nullptr) {}
  virtual ~moblie();
  explicit constexpr moblie(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  moblie(const moblie& from);
  moblie(moblie&& from) noexcept
    : moblie() {
    *this = ::std::move(from);
  }

  inline moblie& operator=(const moblie& from) {
    CopyFrom(from);
    return *this;
  }
  inline moblie& operator=(moblie&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const moblie& default_instance() {
    return *internal_default_instance();
  }
  static inline const moblie* internal_default_instance() {
    return reinterpret_cast<const moblie*>(
               &_moblie_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(moblie& a, moblie& b) {
    a.Swap(&b);
  }
  inline void Swap(moblie* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(moblie* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline moblie* New() const final {
    return CreateMaybeMessage<moblie>(nullptr);
  }

  moblie* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<moblie>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const moblie& from);
  void MergeFrom(const moblie& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(moblie* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mycell.moblie.moblie";
  }
  protected:
  explicit moblie(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_moblie_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAppsFieldNumber = 4,
    kNameFieldNumber = 1,
    kSystemNameFieldNumber = 3,
    kModelFieldNumber = 2,
  };
  // repeated .App apps = 4;
  int apps_size() const;
  private:
  int _internal_apps_size() const;
  public:
  void clear_apps();
  ::App* mutable_apps(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::App >*
      mutable_apps();
  private:
  const ::App& _internal_apps(int index) const;
  ::App* _internal_add_apps();
  public:
  const ::App& apps(int index) const;
  ::App* add_apps();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::App >&
      apps() const;

  // string name = 1;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // string systemName = 3;
  void clear_systemname();
  const std::string& systemname() const;
  void set_systemname(const std::string& value);
  void set_systemname(std::string&& value);
  void set_systemname(const char* value);
  void set_systemname(const char* value, size_t size);
  std::string* mutable_systemname();
  std::string* release_systemname();
  void set_allocated_systemname(std::string* systemname);
  private:
  const std::string& _internal_systemname() const;
  void _internal_set_systemname(const std::string& value);
  std::string* _internal_mutable_systemname();
  public:

  // .mycell.moblie.Brand model = 2;
  void clear_model();
  ::mycell::moblie::Brand model() const;
  void set_model(::mycell::moblie::Brand value);
  private:
  ::mycell::moblie::Brand _internal_model() const;
  void _internal_set_model(::mycell::moblie::Brand value);
  public:

  // @@protoc_insertion_point(class_scope:mycell.moblie.moblie)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::App > apps_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr systemname_;
  int model_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_moblie_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// moblie

// string name = 1;
inline void moblie::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& moblie::name() const {
  // @@protoc_insertion_point(field_get:mycell.moblie.moblie.name)
  return _internal_name();
}
inline void moblie::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:mycell.moblie.moblie.name)
}
inline std::string* moblie::mutable_name() {
  // @@protoc_insertion_point(field_mutable:mycell.moblie.moblie.name)
  return _internal_mutable_name();
}
inline const std::string& moblie::_internal_name() const {
  return name_.Get();
}
inline void moblie::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void moblie::set_name(std::string&& value) {
  
  name_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:mycell.moblie.moblie.name)
}
inline void moblie::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:mycell.moblie.moblie.name)
}
inline void moblie::set_name(const char* value,
    size_t size) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:mycell.moblie.moblie.name)
}
inline std::string* moblie::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* moblie::release_name() {
  // @@protoc_insertion_point(field_release:mycell.moblie.moblie.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void moblie::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:mycell.moblie.moblie.name)
}

// .mycell.moblie.Brand model = 2;
inline void moblie::clear_model() {
  model_ = 0;
}
inline ::mycell::moblie::Brand moblie::_internal_model() const {
  return static_cast< ::mycell::moblie::Brand >(model_);
}
inline ::mycell::moblie::Brand moblie::model() const {
  // @@protoc_insertion_point(field_get:mycell.moblie.moblie.model)
  return _internal_model();
}
inline void moblie::_internal_set_model(::mycell::moblie::Brand value) {
  
  model_ = value;
}
inline void moblie::set_model(::mycell::moblie::Brand value) {
  _internal_set_model(value);
  // @@protoc_insertion_point(field_set:mycell.moblie.moblie.model)
}

// string systemName = 3;
inline void moblie::clear_systemname() {
  systemname_.ClearToEmpty();
}
inline const std::string& moblie::systemname() const {
  // @@protoc_insertion_point(field_get:mycell.moblie.moblie.systemName)
  return _internal_systemname();
}
inline void moblie::set_systemname(const std::string& value) {
  _internal_set_systemname(value);
  // @@protoc_insertion_point(field_set:mycell.moblie.moblie.systemName)
}
inline std::string* moblie::mutable_systemname() {
  // @@protoc_insertion_point(field_mutable:mycell.moblie.moblie.systemName)
  return _internal_mutable_systemname();
}
inline const std::string& moblie::_internal_systemname() const {
  return systemname_.Get();
}
inline void moblie::_internal_set_systemname(const std::string& value) {
  
  systemname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void moblie::set_systemname(std::string&& value) {
  
  systemname_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:mycell.moblie.moblie.systemName)
}
inline void moblie::set_systemname(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  systemname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:mycell.moblie.moblie.systemName)
}
inline void moblie::set_systemname(const char* value,
    size_t size) {
  
  systemname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:mycell.moblie.moblie.systemName)
}
inline std::string* moblie::_internal_mutable_systemname() {
  
  return systemname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* moblie::release_systemname() {
  // @@protoc_insertion_point(field_release:mycell.moblie.moblie.systemName)
  return systemname_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void moblie::set_allocated_systemname(std::string* systemname) {
  if (systemname != nullptr) {
    
  } else {
    
  }
  systemname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), systemname,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:mycell.moblie.moblie.systemName)
}

// repeated .App apps = 4;
inline int moblie::_internal_apps_size() const {
  return apps_.size();
}
inline int moblie::apps_size() const {
  return _internal_apps_size();
}
inline ::App* moblie::mutable_apps(int index) {
  // @@protoc_insertion_point(field_mutable:mycell.moblie.moblie.apps)
  return apps_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::App >*
moblie::mutable_apps() {
  // @@protoc_insertion_point(field_mutable_list:mycell.moblie.moblie.apps)
  return &apps_;
}
inline const ::App& moblie::_internal_apps(int index) const {
  return apps_.Get(index);
}
inline const ::App& moblie::apps(int index) const {
  // @@protoc_insertion_point(field_get:mycell.moblie.moblie.apps)
  return _internal_apps(index);
}
inline ::App* moblie::_internal_add_apps() {
  return apps_.Add();
}
inline ::App* moblie::add_apps() {
  // @@protoc_insertion_point(field_add:mycell.moblie.moblie.apps)
  return _internal_add_apps();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::App >&
moblie::apps() const {
  // @@protoc_insertion_point(field_list:mycell.moblie.moblie.apps)
  return apps_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace moblie
}  // namespace mycell

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::mycell::moblie::Brand> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::mycell::moblie::Brand>() {
  return ::mycell::moblie::Brand_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_moblie_2eproto
