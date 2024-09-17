cmake_minimum_required(VERSION 3.8)

project(grpc-long-compp)

find_package(Threads REQUIRED)

find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)

find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")
set(_GRPC_GRPCPP gRPC::grpc++)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)

#find_package(OpenMP REQUIRED)
#find_package(CUDAToolkit REQUIRED)
#message(STATUS "CUDA Libs dir : ${CUDA_TOOLKIT_ROOT_DIR}")
#find_package(OpenCV REQUIRED)
#message(STATUS "OpenCV include dir : ${OpenCV_INCLUDE_DIRS}")

message("- CMAKE_CURRENT_BINARY_DIR = " ${CMAKE_CURRENT_BINARY_DIR})
message("- _PROTOBUF_PROTOC = " ${_PROTOBUF_PROTOC})
message("- _GRPC_CPP_PLUGIN_EXECUTABLE = " ${_GRPC_CPP_PLUGIN_EXECUTABLE})
message("- GRPC_LIBRARIES = " ${GRPC_LIBS})

#Proto file
get_filename_component(test_proto "${CMAKE_CURRENT_BINARY_DIR}/../protos/test.proto" ABSOLUTE)
get_filename_component(test_proto_path "${test_proto}" PATH)
message("- proto-file = " ${test_proto})
message("- proto-path = " ${test_proto_path})

# Generated sources
set(test_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/../protos/test.pb.cc")
set(test_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/../protos/test.pb.h")
set(test_grpc_srcs  "${CMAKE_CURRENT_BINARY_DIR}/../protos/test.grpc.pb.cc")
set(test_grpc_hdrs  "${CMAKE_CURRENT_BINARY_DIR}/../protos/test.grpc.pb.h")

#add_custom_command(
#      OUTPUT "${test_proto_srcs}" "${test_proto_hdrs}" "${test_grpc_srcs}" "${test_grpc_hdrs}"
#      COMMAND ${_PROTOBUF_PROTOC} #/usr/local/bin/protoc
#      ARGS --grpc_out "${test_proto_path}"
#        --cpp_out "${test_proto_path}"
#        -I "${test_proto_path}"
#        --plugin=protoc-gen-grpc=${_GRPC_CPP_PLUGIN_EXECUTABLE}#"/usr/local/bin/grpc_cpp_plugin"
#        "${test_proto}"
#      DEPENDS "${test_proto}")

# Include generated *.pb.h files
include_directories( 
    "${CMAKE_CURRENT_BINARY_DIR}/../proto"
    )

link_directories(
    )

# hw_grpc_proto
add_library(test_grpc_proto
  ${test_grpc_srcs}
  ${test_grpc_hdrs}
  ${test_proto_srcs}
  ${test_proto_hdrs})
target_link_libraries(test_grpc_proto #gRPC::grpc++)
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF} )

# Project target
add_executable(server main.cpp)
target_link_libraries(server
    test_grpc_proto
    #gRPC::grpc++ gRPC::grpc++_reflection gRPC::grpc++_alts
    absl::flags absl::flags_parse 
    #absl_log_internal_check_op absl_log_internal_conditions absl_log_internal_format absl_log_internal_globals absl_log_internal_log_sink_set 
    #absl_log_internal_message absl_log_internal_nullguard absl_log_internal_proto absl_log_severity absl_log_sink #grpc++_reflection grpc++ grpc #grpc++_reflection 
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
)

#add_executable(client client.cpp)
#target_link_libraries(client 
#    vecsearch_grpc_proto
#    ${GRPC_LIB_FILES})