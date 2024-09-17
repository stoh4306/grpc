// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test.proto
#ifndef GRPC_test_2eproto__INCLUDED
#define GRPC_test_2eproto__INCLUDED

#include "test.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace test {

class testService final {
 public:
  static constexpr char const* service_full_name() {
    return "test.testService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status compute(::grpc::ClientContext* context, const ::test::TestRequest& request, ::test::TestResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::test::TestResponse>> Asynccompute(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::test::TestResponse>>(AsynccomputeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::test::TestResponse>> PrepareAsynccompute(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::test::TestResponse>>(PrepareAsynccomputeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderInterface< ::test::FrameData>> computeStream(::grpc::ClientContext* context, const ::test::TestRequest& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::test::FrameData>>(computeStreamRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::test::FrameData>> AsynccomputeStream(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::test::FrameData>>(AsynccomputeStreamRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::test::FrameData>> PrepareAsynccomputeStream(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::test::FrameData>>(PrepareAsynccomputeStreamRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void compute(::grpc::ClientContext* context, const ::test::TestRequest* request, ::test::TestResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void compute(::grpc::ClientContext* context, const ::test::TestRequest* request, ::test::TestResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void computeStream(::grpc::ClientContext* context, const ::test::TestRequest* request, ::grpc::ClientReadReactor< ::test::FrameData>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::test::TestResponse>* AsynccomputeRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::test::TestResponse>* PrepareAsynccomputeRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::test::FrameData>* computeStreamRaw(::grpc::ClientContext* context, const ::test::TestRequest& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::test::FrameData>* AsynccomputeStreamRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::test::FrameData>* PrepareAsynccomputeStreamRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status compute(::grpc::ClientContext* context, const ::test::TestRequest& request, ::test::TestResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::test::TestResponse>> Asynccompute(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::test::TestResponse>>(AsynccomputeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::test::TestResponse>> PrepareAsynccompute(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::test::TestResponse>>(PrepareAsynccomputeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::test::FrameData>> computeStream(::grpc::ClientContext* context, const ::test::TestRequest& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::test::FrameData>>(computeStreamRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::test::FrameData>> AsynccomputeStream(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::test::FrameData>>(AsynccomputeStreamRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::test::FrameData>> PrepareAsynccomputeStream(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::test::FrameData>>(PrepareAsynccomputeStreamRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void compute(::grpc::ClientContext* context, const ::test::TestRequest* request, ::test::TestResponse* response, std::function<void(::grpc::Status)>) override;
      void compute(::grpc::ClientContext* context, const ::test::TestRequest* request, ::test::TestResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void computeStream(::grpc::ClientContext* context, const ::test::TestRequest* request, ::grpc::ClientReadReactor< ::test::FrameData>* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::test::TestResponse>* AsynccomputeRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::test::TestResponse>* PrepareAsynccomputeRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::test::FrameData>* computeStreamRaw(::grpc::ClientContext* context, const ::test::TestRequest& request) override;
    ::grpc::ClientAsyncReader< ::test::FrameData>* AsynccomputeStreamRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::test::FrameData>* PrepareAsynccomputeStreamRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_compute_;
    const ::grpc::internal::RpcMethod rpcmethod_computeStream_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status compute(::grpc::ServerContext* context, const ::test::TestRequest* request, ::test::TestResponse* response);
    virtual ::grpc::Status computeStream(::grpc::ServerContext* context, const ::test::TestRequest* request, ::grpc::ServerWriter< ::test::FrameData>* writer);
  };
  template <class BaseClass>
  class WithAsyncMethod_compute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_compute() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_compute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status compute(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::test::TestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestcompute(::grpc::ServerContext* context, ::test::TestRequest* request, ::grpc::ServerAsyncResponseWriter< ::test::TestResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_computeStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_computeStream() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_computeStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status computeStream(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::grpc::ServerWriter< ::test::FrameData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestcomputeStream(::grpc::ServerContext* context, ::test::TestRequest* request, ::grpc::ServerAsyncWriter< ::test::FrameData>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_compute<WithAsyncMethod_computeStream<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_compute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_compute() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::test::TestRequest, ::test::TestResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::test::TestRequest* request, ::test::TestResponse* response) { return this->compute(context, request, response); }));}
    void SetMessageAllocatorFor_compute(
        ::grpc::MessageAllocator< ::test::TestRequest, ::test::TestResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::test::TestRequest, ::test::TestResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_compute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status compute(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::test::TestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* compute(
      ::grpc::CallbackServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::test::TestResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_computeStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_computeStream() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::test::TestRequest, ::test::FrameData>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::test::TestRequest* request) { return this->computeStream(context, request); }));
    }
    ~WithCallbackMethod_computeStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status computeStream(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::grpc::ServerWriter< ::test::FrameData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::test::FrameData>* computeStream(
      ::grpc::CallbackServerContext* /*context*/, const ::test::TestRequest* /*request*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_compute<WithCallbackMethod_computeStream<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_compute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_compute() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_compute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status compute(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::test::TestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_computeStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_computeStream() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_computeStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status computeStream(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::grpc::ServerWriter< ::test::FrameData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_compute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_compute() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_compute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status compute(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::test::TestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestcompute(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_computeStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_computeStream() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_computeStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status computeStream(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::grpc::ServerWriter< ::test::FrameData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestcomputeStream(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_compute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_compute() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->compute(context, request, response); }));
    }
    ~WithRawCallbackMethod_compute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status compute(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::test::TestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* compute(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_computeStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_computeStream() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const::grpc::ByteBuffer* request) { return this->computeStream(context, request); }));
    }
    ~WithRawCallbackMethod_computeStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status computeStream(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::grpc::ServerWriter< ::test::FrameData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* computeStream(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_compute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_compute() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::test::TestRequest, ::test::TestResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::test::TestRequest, ::test::TestResponse>* streamer) {
                       return this->Streamedcompute(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_compute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status compute(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::test::TestResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streamedcompute(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::test::TestRequest,::test::TestResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_compute<Service > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_computeStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_computeStream() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::test::TestRequest, ::test::FrameData>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerSplitStreamer<
                     ::test::TestRequest, ::test::FrameData>* streamer) {
                       return this->StreamedcomputeStream(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_computeStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status computeStream(::grpc::ServerContext* /*context*/, const ::test::TestRequest* /*request*/, ::grpc::ServerWriter< ::test::FrameData>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedcomputeStream(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::test::TestRequest,::test::FrameData>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_computeStream<Service > SplitStreamedService;
  typedef WithStreamedUnaryMethod_compute<WithSplitStreamingMethod_computeStream<Service > > StreamedService;
};

}  // namespace test


#endif  // GRPC_test_2eproto__INCLUDED
