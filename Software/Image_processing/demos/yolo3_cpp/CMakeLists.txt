cmake_minimum_required(VERSION 2.8)
#OpenCV4 must enable c++11
add_definitions(-std=c++11)
#setOpenCV_DIR
#set(OpenCV_DIR "/usr/local/share/opencv4")

project(classifyObjects)

find_package(OpenCV 4 REQUIRED)
set(arch "arm")
#set(arch "64")

#print OpenCV_VERSION on terminal
message(STATUS "OpenCV_VERSION:" ${OpenCV_VERSION})

file(GLOB native_srcs "src/classifyObjects_${arch}.cpp")

add_executable(${PROJECT_NAME} ${native_srcs})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )

