// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: weather.proto

#include "weather.pb.h"
#include "weather.grpc.pb.h"

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
namespace weather {

static const char* Weather_method_names[] = {
  "/weather.Weather/getLivesWeather",
  "/weather.Weather/getForecastWeather",
};

std::unique_ptr< Weather::Stub> Weather::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Weather::Stub> stub(new Weather::Stub(channel, options));
  return stub;
}

Weather::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_getLivesWeather_(Weather_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getForecastWeather_(Weather_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Weather::Stub::getLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::weather::LivesWeatherReplay* response) {
  return ::grpc::internal::BlockingUnaryCall< ::weather::UserInfo, ::weather::LivesWeatherReplay, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_getLivesWeather_, context, request, response);
}

void Weather::Stub::async::getLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::LivesWeatherReplay* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::weather::UserInfo, ::weather::LivesWeatherReplay, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getLivesWeather_, context, request, response, std::move(f));
}

void Weather::Stub::async::getLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::LivesWeatherReplay* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getLivesWeather_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::weather::LivesWeatherReplay>* Weather::Stub::PrepareAsyncgetLivesWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::weather::LivesWeatherReplay, ::weather::UserInfo, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_getLivesWeather_, context, request);
}

::grpc::ClientAsyncResponseReader< ::weather::LivesWeatherReplay>* Weather::Stub::AsyncgetLivesWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetLivesWeatherRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Weather::Stub::getForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::weather::ForecastWeatherReplay* response) {
  return ::grpc::internal::BlockingUnaryCall< ::weather::UserInfo, ::weather::ForecastWeatherReplay, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_getForecastWeather_, context, request, response);
}

void Weather::Stub::async::getForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::ForecastWeatherReplay* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::weather::UserInfo, ::weather::ForecastWeatherReplay, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getForecastWeather_, context, request, response, std::move(f));
}

void Weather::Stub::async::getForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::ForecastWeatherReplay* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_getForecastWeather_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::weather::ForecastWeatherReplay>* Weather::Stub::PrepareAsyncgetForecastWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::weather::ForecastWeatherReplay, ::weather::UserInfo, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_getForecastWeather_, context, request);
}

::grpc::ClientAsyncResponseReader< ::weather::ForecastWeatherReplay>* Weather::Stub::AsyncgetForecastWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncgetForecastWeatherRaw(context, request, cq);
  result->StartCall();
  return result;
}

Weather::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Weather_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Weather::Service, ::weather::UserInfo, ::weather::LivesWeatherReplay, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Weather::Service* service,
             ::grpc::ServerContext* ctx,
             const ::weather::UserInfo* req,
             ::weather::LivesWeatherReplay* resp) {
               return service->getLivesWeather(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Weather_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Weather::Service, ::weather::UserInfo, ::weather::ForecastWeatherReplay, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Weather::Service* service,
             ::grpc::ServerContext* ctx,
             const ::weather::UserInfo* req,
             ::weather::ForecastWeatherReplay* resp) {
               return service->getForecastWeather(ctx, req, resp);
             }, this)));
}

Weather::Service::~Service() {
}

::grpc::Status Weather::Service::getLivesWeather(::grpc::ServerContext* context, const ::weather::UserInfo* request, ::weather::LivesWeatherReplay* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Weather::Service::getForecastWeather(::grpc::ServerContext* context, const ::weather::UserInfo* request, ::weather::ForecastWeatherReplay* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace weather

