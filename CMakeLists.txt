cmake_minimum_required(VERSION 3.10)
project(cloud_run_hello)

# Find the Functions Framework for C++
# This will install the framework if it is not already installed.
find_package(functions-framework-cpp REQUIRED)

# Find the nlohmann-json library
find_package(nlohmann_json REQUIRED)

# Find the mongocxx library
find_package(mongocxx REQUIRED)

# Add the executable
add_executable(cloud_run_hello
    cloud_run_hello.cc
    auth_service.cc
    auth_service.h
    mongodb_service.cc
    mongodb_service.h
)

# Link against the Functions Framework library, nlohmann-json and mongocxx
target_link_libraries(cloud_run_hello
    PRIVATE
    functions-framework-cpp::functions-framework-cpp
    nlohmann_json::nlohmann_json
    mongocxx::mongocxx
)
