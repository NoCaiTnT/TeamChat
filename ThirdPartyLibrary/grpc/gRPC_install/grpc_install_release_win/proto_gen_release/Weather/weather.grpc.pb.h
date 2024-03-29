// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: weather.proto
// Original file comments:
// Copyright 2015 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_weather_2eproto__INCLUDED
#define GRPC_weather_2eproto__INCLUDED

#include "weather.pb.h"

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

namespace weather {

class Weather final {
 public:
  static constexpr char const* service_full_name() {
    return "weather.Weather";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status getLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::weather::LivesWeatherReplay* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::weather::LivesWeatherReplay>> AsyncgetLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::weather::LivesWeatherReplay>>(AsyncgetLivesWeatherRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::weather::LivesWeatherReplay>> PrepareAsyncgetLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::weather::LivesWeatherReplay>>(PrepareAsyncgetLivesWeatherRaw(context, request, cq));
    }
    virtual ::grpc::Status getForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::weather::ForecastWeatherReplay* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::weather::ForecastWeatherReplay>> AsyncgetForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::weather::ForecastWeatherReplay>>(AsyncgetForecastWeatherRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::weather::ForecastWeatherReplay>> PrepareAsyncgetForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::weather::ForecastWeatherReplay>>(PrepareAsyncgetForecastWeatherRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void getLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::LivesWeatherReplay* response, std::function<void(::grpc::Status)>) = 0;
      virtual void getLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::LivesWeatherReplay* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void getForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::ForecastWeatherReplay* response, std::function<void(::grpc::Status)>) = 0;
      virtual void getForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::ForecastWeatherReplay* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::weather::LivesWeatherReplay>* AsyncgetLivesWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::weather::LivesWeatherReplay>* PrepareAsyncgetLivesWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::weather::ForecastWeatherReplay>* AsyncgetForecastWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::weather::ForecastWeatherReplay>* PrepareAsyncgetForecastWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status getLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::weather::LivesWeatherReplay* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::weather::LivesWeatherReplay>> AsyncgetLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::weather::LivesWeatherReplay>>(AsyncgetLivesWeatherRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::weather::LivesWeatherReplay>> PrepareAsyncgetLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::weather::LivesWeatherReplay>>(PrepareAsyncgetLivesWeatherRaw(context, request, cq));
    }
    ::grpc::Status getForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::weather::ForecastWeatherReplay* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::weather::ForecastWeatherReplay>> AsyncgetForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::weather::ForecastWeatherReplay>>(AsyncgetForecastWeatherRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::weather::ForecastWeatherReplay>> PrepareAsyncgetForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::weather::ForecastWeatherReplay>>(PrepareAsyncgetForecastWeatherRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void getLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::LivesWeatherReplay* response, std::function<void(::grpc::Status)>) override;
      void getLivesWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::LivesWeatherReplay* response, ::grpc::ClientUnaryReactor* reactor) override;
      void getForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::ForecastWeatherReplay* response, std::function<void(::grpc::Status)>) override;
      void getForecastWeather(::grpc::ClientContext* context, const ::weather::UserInfo* request, ::weather::ForecastWeatherReplay* response, ::grpc::ClientUnaryReactor* reactor) override;
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
    ::grpc::ClientAsyncResponseReader< ::weather::LivesWeatherReplay>* AsyncgetLivesWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::weather::LivesWeatherReplay>* PrepareAsyncgetLivesWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::weather::ForecastWeatherReplay>* AsyncgetForecastWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::weather::ForecastWeatherReplay>* PrepareAsyncgetForecastWeatherRaw(::grpc::ClientContext* context, const ::weather::UserInfo& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_getLivesWeather_;
    const ::grpc::internal::RpcMethod rpcmethod_getForecastWeather_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status getLivesWeather(::grpc::ServerContext* context, const ::weather::UserInfo* request, ::weather::LivesWeatherReplay* response);
    virtual ::grpc::Status getForecastWeather(::grpc::ServerContext* context, const ::weather::UserInfo* request, ::weather::ForecastWeatherReplay* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_getLivesWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_getLivesWeather() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_getLivesWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getLivesWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::LivesWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetLivesWeather(::grpc::ServerContext* context, ::weather::UserInfo* request, ::grpc::ServerAsyncResponseWriter< ::weather::LivesWeatherReplay>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_getForecastWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_getForecastWeather() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_getForecastWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getForecastWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::ForecastWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetForecastWeather(::grpc::ServerContext* context, ::weather::UserInfo* request, ::grpc::ServerAsyncResponseWriter< ::weather::ForecastWeatherReplay>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_getLivesWeather<WithAsyncMethod_getForecastWeather<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_getLivesWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_getLivesWeather() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::weather::UserInfo, ::weather::LivesWeatherReplay>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::weather::UserInfo* request, ::weather::LivesWeatherReplay* response) { return this->getLivesWeather(context, request, response); }));}
    void SetMessageAllocatorFor_getLivesWeather(
        ::grpc::MessageAllocator< ::weather::UserInfo, ::weather::LivesWeatherReplay>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::weather::UserInfo, ::weather::LivesWeatherReplay>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_getLivesWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getLivesWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::LivesWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* getLivesWeather(
      ::grpc::CallbackServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::LivesWeatherReplay* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_getForecastWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_getForecastWeather() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::weather::UserInfo, ::weather::ForecastWeatherReplay>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::weather::UserInfo* request, ::weather::ForecastWeatherReplay* response) { return this->getForecastWeather(context, request, response); }));}
    void SetMessageAllocatorFor_getForecastWeather(
        ::grpc::MessageAllocator< ::weather::UserInfo, ::weather::ForecastWeatherReplay>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::weather::UserInfo, ::weather::ForecastWeatherReplay>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_getForecastWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getForecastWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::ForecastWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* getForecastWeather(
      ::grpc::CallbackServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::ForecastWeatherReplay* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_getLivesWeather<WithCallbackMethod_getForecastWeather<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_getLivesWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_getLivesWeather() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_getLivesWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getLivesWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::LivesWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_getForecastWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_getForecastWeather() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_getForecastWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getForecastWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::ForecastWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_getLivesWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_getLivesWeather() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_getLivesWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getLivesWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::LivesWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetLivesWeather(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_getForecastWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_getForecastWeather() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_getForecastWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getForecastWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::ForecastWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestgetForecastWeather(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_getLivesWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_getLivesWeather() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->getLivesWeather(context, request, response); }));
    }
    ~WithRawCallbackMethod_getLivesWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getLivesWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::LivesWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* getLivesWeather(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_getForecastWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_getForecastWeather() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->getForecastWeather(context, request, response); }));
    }
    ~WithRawCallbackMethod_getForecastWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status getForecastWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::ForecastWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* getForecastWeather(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_getLivesWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_getLivesWeather() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::weather::UserInfo, ::weather::LivesWeatherReplay>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::weather::UserInfo, ::weather::LivesWeatherReplay>* streamer) {
                       return this->StreamedgetLivesWeather(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_getLivesWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status getLivesWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::LivesWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedgetLivesWeather(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::weather::UserInfo,::weather::LivesWeatherReplay>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_getForecastWeather : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_getForecastWeather() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::weather::UserInfo, ::weather::ForecastWeatherReplay>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::weather::UserInfo, ::weather::ForecastWeatherReplay>* streamer) {
                       return this->StreamedgetForecastWeather(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_getForecastWeather() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status getForecastWeather(::grpc::ServerContext* /*context*/, const ::weather::UserInfo* /*request*/, ::weather::ForecastWeatherReplay* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedgetForecastWeather(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::weather::UserInfo,::weather::ForecastWeatherReplay>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_getLivesWeather<WithStreamedUnaryMethod_getForecastWeather<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_getLivesWeather<WithStreamedUnaryMethod_getForecastWeather<Service > > StreamedService;
};

}  // namespace weather


#endif  // GRPC_weather_2eproto__INCLUDED
