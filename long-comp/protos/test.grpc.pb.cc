// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test.proto

#include "test.pb.h"
#include "test.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace test {

static const char* testService_method_names[] = {
  "/test.testService/compute",
  "/test.testService/computeStream",
};

std::unique_ptr< testService::Stub> testService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< testService::Stub> stub(new testService::Stub(channel, options));
  return stub;
}

testService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_compute_(testService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_computeStream_(testService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  {}

::grpc::Status testService::Stub::compute(::grpc::ClientContext* context, const ::test::TestRequest& request, ::test::TestResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::test::TestRequest, ::test::TestResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_compute_, context, request, response);
}

void testService::Stub::async::compute(::grpc::ClientContext* context, const ::test::TestRequest* request, ::test::TestResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::test::TestRequest, ::test::TestResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_compute_, context, request, response, std::move(f));
}

void testService::Stub::async::compute(::grpc::ClientContext* context, const ::test::TestRequest* request, ::test::TestResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_compute_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::test::TestResponse>* testService::Stub::PrepareAsynccomputeRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::test::TestResponse, ::test::TestRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_compute_, context, request);
}

::grpc::ClientAsyncResponseReader< ::test::TestResponse>* testService::Stub::AsynccomputeRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynccomputeRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReader< ::test::FrameData>* testService::Stub::computeStreamRaw(::grpc::ClientContext* context, const ::test::TestRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::test::FrameData>::Create(channel_.get(), rpcmethod_computeStream_, context, request);
}

void testService::Stub::async::computeStream(::grpc::ClientContext* context, const ::test::TestRequest* request, ::grpc::ClientReadReactor< ::test::FrameData>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::test::FrameData>::Create(stub_->channel_.get(), stub_->rpcmethod_computeStream_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::test::FrameData>* testService::Stub::AsynccomputeStreamRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::test::FrameData>::Create(channel_.get(), cq, rpcmethod_computeStream_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::test::FrameData>* testService::Stub::PrepareAsynccomputeStreamRaw(::grpc::ClientContext* context, const ::test::TestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::test::FrameData>::Create(channel_.get(), cq, rpcmethod_computeStream_, context, request, false, nullptr);
}

testService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      testService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< testService::Service, ::test::TestRequest, ::test::TestResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](testService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::test::TestRequest* req,
             ::test::TestResponse* resp) {
               return service->compute(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      testService_method_names[1],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< testService::Service, ::test::TestRequest, ::test::FrameData>(
          [](testService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::test::TestRequest* req,
             ::grpc::ServerWriter<::test::FrameData>* writer) {
               return service->computeStream(ctx, req, writer);
             }, this)));
}

testService::Service::~Service() {
}

::grpc::Status testService::Service::compute(::grpc::ServerContext* context, const ::test::TestRequest* request, ::test::TestResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status testService::Service::computeStream(::grpc::ServerContext* context, const ::test::TestRequest* request, ::grpc::ServerWriter< ::test::FrameData>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace test

