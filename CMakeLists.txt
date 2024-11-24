cmake_minimum_required(VERSION 3.5)
project(IMGUI_DEMO VERSION 1.0)

find_package(OpenGL REQUIRED) #Opengl32.lib

set(GLEW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/GLEW)
include_directories(${GLEW_DIR}/include/)
include_directories(${GLEW_DIR}/include/GL/)
file(GLOB LIB_GLEW "${GLEW_DIR}/lib/Release/x64/*.lib")
message("GLEW_DIR:" ${GLEW_DIR})

set(GLFW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/GLFW)
include_directories(${GLFW_DIR}/include/)
include_directories(${GLFW_DIR}/include/GLFW/)
file(GLOB LIB_GLFW "${GLFW_DIR}/lib-vc2022/*.lib")
message("GLFW_DIR:" ${GLFW_DIR})

set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/IMGUI/)
include_directories(${IMGUI_DIR})
aux_source_directory(${IMGUI_DIR} IMGUI_SRC)
set(IMGUI_BACKENDS ${CMAKE_CURRENT_SOURCE_DIR}/third_party/IMGUI/backends/)
include_directories(${IMGUI_BACKENDS})
aux_source_directory(${IMGUI_BACKENDS}/ IMGUI_BACKENDS_SRC)
message("IMGUI_DIR:" ${IMGUI_DIR})
message("IMGUI_SRC_PATH:" ${IMGUI_SRC})

set(EXE_NAME ${PROJECT_NAME}${CMAKE_PROJECT_VERSION})
add_executable(${EXE_NAME} ${IMGUI_SRC} ${IMGUI_BACKENDS_SRC} main.cpp )
target_link_libraries(${EXE_NAME} ${LIB_GLFW} ${LIB_GLEW} ${OPENGL_LIBRARIES})

