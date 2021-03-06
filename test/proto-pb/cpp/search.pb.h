// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: search.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_search_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_search_2eproto

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_search_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_search_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_search_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_search_2eproto_metadata_getter(int index);
class SearchRequest;
struct SearchRequestDefaultTypeInternal;
extern SearchRequestDefaultTypeInternal _SearchRequest_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::SearchRequest* Arena::CreateMaybeMessage<::SearchRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class SearchRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SearchRequest) */ {
 public:
  inline SearchRequest() : SearchRequest(nullptr) {}
  virtual ~SearchRequest();
  explicit constexpr SearchRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  SearchRequest(const SearchRequest& from);
  SearchRequest(SearchRequest&& from) noexcept
    : SearchRequest() {
    *this = ::std::move(from);
  }

  inline SearchRequest& operator=(const SearchRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline SearchRequest& operator=(SearchRequest&& from) noexcept {
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
  static const SearchRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const SearchRequest* internal_default_instance() {
    return reinterpret_cast<const SearchRequest*>(
               &_SearchRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SearchRequest& a, SearchRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(SearchRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SearchRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SearchRequest* New() const final {
    return CreateMaybeMessage<SearchRequest>(nullptr);
  }

  SearchRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SearchRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SearchRequest& from);
  void MergeFrom(const SearchRequest& from);
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
  void InternalSwap(SearchRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SearchRequest";
  }
  protected:
  explicit SearchRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_search_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kQueryFieldNumber = 1,
    kPageNumberFieldNumber = 2,
    kResultPerPageFieldNumber = 3,
  };
  // string query = 1;
  void clear_query();
  const std::string& query() const;
  void set_query(const std::string& value);
  void set_query(std::string&& value);
  void set_query(const char* value);
  void set_query(const char* value, size_t size);
  std::string* mutable_query();
  std::string* release_query();
  void set_allocated_query(std::string* query);
  private:
  const std::string& _internal_query() const;
  void _internal_set_query(const std::string& value);
  std::string* _internal_mutable_query();
  public:

  // int32 page_number = 2;
  void clear_page_number();
  ::PROTOBUF_NAMESPACE_ID::int32 page_number() const;
  void set_page_number(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_page_number() const;
  void _internal_set_page_number(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 result_per_page = 3;
  void clear_result_per_page();
  ::PROTOBUF_NAMESPACE_ID::int32 result_per_page() const;
  void set_result_per_page(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_result_per_page() const;
  void _internal_set_result_per_page(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:SearchRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr query_;
  ::PROTOBUF_NAMESPACE_ID::int32 page_number_;
  ::PROTOBUF_NAMESPACE_ID::int32 result_per_page_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_search_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SearchRequest

// string query = 1;
inline void SearchRequest::clear_query() {
  query_.ClearToEmpty();
}
inline const std::string& SearchRequest::query() const {
  // @@protoc_insertion_point(field_get:SearchRequest.query)
  return _internal_query();
}
inline void SearchRequest::set_query(const std::string& value) {
  _internal_set_query(value);
  // @@protoc_insertion_point(field_set:SearchRequest.query)
}
inline std::string* SearchRequest::mutable_query() {
  // @@protoc_insertion_point(field_mutable:SearchRequest.query)
  return _internal_mutable_query();
}
inline const std::string& SearchRequest::_internal_query() const {
  return query_.Get();
}
inline void SearchRequest::_internal_set_query(const std::string& value) {
  
  query_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SearchRequest::set_query(std::string&& value) {
  
  query_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:SearchRequest.query)
}
inline void SearchRequest::set_query(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  query_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:SearchRequest.query)
}
inline void SearchRequest::set_query(const char* value,
    size_t size) {
  
  query_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:SearchRequest.query)
}
inline std::string* SearchRequest::_internal_mutable_query() {
  
  return query_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SearchRequest::release_query() {
  // @@protoc_insertion_point(field_release:SearchRequest.query)
  return query_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SearchRequest::set_allocated_query(std::string* query) {
  if (query != nullptr) {
    
  } else {
    
  }
  query_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), query,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:SearchRequest.query)
}

// int32 page_number = 2;
inline void SearchRequest::clear_page_number() {
  page_number_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SearchRequest::_internal_page_number() const {
  return page_number_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SearchRequest::page_number() const {
  // @@protoc_insertion_point(field_get:SearchRequest.page_number)
  return _internal_page_number();
}
inline void SearchRequest::_internal_set_page_number(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  page_number_ = value;
}
inline void SearchRequest::set_page_number(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_page_number(value);
  // @@protoc_insertion_point(field_set:SearchRequest.page_number)
}

// int32 result_per_page = 3;
inline void SearchRequest::clear_result_per_page() {
  result_per_page_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SearchRequest::_internal_result_per_page() const {
  return result_per_page_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SearchRequest::result_per_page() const {
  // @@protoc_insertion_point(field_get:SearchRequest.result_per_page)
  return _internal_result_per_page();
}
inline void SearchRequest::_internal_set_result_per_page(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  result_per_page_ = value;
}
inline void SearchRequest::set_result_per_page(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_result_per_page(value);
  // @@protoc_insertion_point(field_set:SearchRequest.result_per_page)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_search_2eproto
