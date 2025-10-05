cmake_minimum_required(VERSION 3.10)
project(ConsumerService)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)
find_package(cppkafka REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(consumer consumer.cpp)
target_link_libraries(consumer PRIVATE cppkafka nlohmann_json::nlohmann_json Boost::boost)

