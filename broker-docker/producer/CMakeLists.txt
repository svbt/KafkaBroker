cmake_minimum_required(VERSION 3.10)
project(ProducerService)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)
find_package(cppkafka REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(producer producer.cpp)
target_link_libraries(producer PRIVATE cppkafka nlohmann_json::nlohmann_json Boost::boost)

