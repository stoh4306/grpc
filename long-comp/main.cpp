#include <grpc/grpc.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include "./protos/test.grpc.pb.h"

#include <chrono>
#include <thread>
#include <atomic>
#include <iostream>
#include <map>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using test::TestRequest;
using test::TestResponse;
using test::FrameData;
using test::testService;

class TestServiceImpl final : public testService::Service {
public:
    Status compute(ServerContext* context, const TestRequest* request, TestResponse* response) override {
        int sessId = sessionId_.fetch_add(1);
        int t = request->time();
        std::this_thread::sleep_for(std::chrono::seconds(t));  
        response->set_sessionid(sessId);
        response->set_message(std::string("sessionId = ")+std::to_string(sessId));
        return Status::OK;
    }

    void startComp(int sessionId, int interval) {
        std::this_thread::sleep_for(std::chrono::seconds(interval));
        //compFinished_.store(1);
        compFinished_[sessionId] = 1;
    }

    Status computeStream(ServerContext* context, const TestRequest* request, grpc::ServerWriter<FrameData>* writer) override {
        int sessId = sessionId_.fetch_add(1);

        compFinished_[sessId] = 0;
        //compFinished_.store(0);

        int t = request->time();
        std::thread t1(&TestServiceImpl::startComp, this, sessId, t);
        t1.detach();

        FrameData frameData;
        int count = 0;

        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            frameData.set_id(count);
            frameData.set_message("in computing...");

            if (compFinished_[sessId] > 0) {
            //if ( compFinished_.load() > 0 ) {
                frameData.set_message("done");
                writer->Write(frameData);
                //compFinished_.store(0);    
                compFinished_[sessId] = 0;
                std::cout << "Computation done!!!" << std::endl;
                break;
            }

            writer->Write(frameData);
            count++;
        }
        compFinished_.erase(sessId);

        return Status::OK;
    }

    TestServiceImpl() : testService::Service() {
        sessionId_.store(0);
        //compFinished_.store(0);
    }
private:
    std::atomic<int> sessionId_;
    //std::atomic<int> compFinished_;
    std::map<int,int> compFinished_;
};


int main(int argc, char** argv) {
    std::string server_address("0.0.0.0:50051");
    TestServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
    
    return 0;
}

