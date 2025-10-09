cmake_minimum_required(VERSION 3.10)
project(consumer_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)
find_package(nlohmann_json REQUIRED)

find_library(RDKAFKA_LIB rdkafka REQUIRED)

# Tell CMake where cppkafka is installed
# (we installed it to /usr/local in the Dockerfile)
link_directories(/usr/local/lib)
include_directories(/usr/local/include)

add_executable(consumer src/consumer.cpp)

target_include_directories(consumer PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${RDKAFKA_INCLUDE_DIRS}
)

target_link_libraries(consumer PRIVATE
    ${Boost_LIBRARIES}
    ${RDKAFKA_LIBRARIES}
    cppkafka
    nlohmann_json::nlohmann_json
)

