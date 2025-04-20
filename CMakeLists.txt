cmake_minimum_required(VERSION 3.19)
project(IMGUI_DEMO VERSION 1.0)

find_package(OpenGL REQUIRED) #Opengl32.lib

set(GLEW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/GLEW)
set(GLEW_HEAD ${GLEW_DIR}/include/GL)
message("GLEW_HEAD:" ${GLEW_HEAD})
file(GLOB LIB_GLEW_x64 "${GLEW_DIR}/lib/Release/x64/*.lib")
message("LIB_GLEW_x64:" ${LIB_GLEW_x64})

set(GLFW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/GLFW)
set(GLFW_HEAD ${GLFW_DIR}/include)
message("GLFW_HEAD:" ${GLFW_HEAD})
file(GLOB LIB_GLFW_x64 ${GLFW_DIR}/lib-vc2022/*.lib)
message("LIB_GLFW_x64:" ${LIB_GLFW_x64})

set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/IMGUI/)
set(IMGUI_HEAD ${IMGUI_DIR})
message("IMGUI_HEAD:" ${IMGUI_HEAD})
file(GLOB IMGUI_SRC ${IMGUI_DIR}/*.cpp)
message("IMGUI_SRC:" ${IMGUI_SRC})
set(IMGUI_BACKENDS ${CMAKE_CURRENT_SOURCE_DIR}/third_party/IMGUI/backends/)
set(IMGUI_BACKENDS_HEAD ${IMGUI_BACKENDS})
message("IMGUI_BACKENDS_HEAD:" ${IMGUI_BACKENDS_HEAD})
file(GLOB IMGUI_BACKENDS_SRC ${IMGUI_BACKENDS}/*.cpp)
message("IMGUI_BACKENDS_SRC:" ${IMGUI_BACKENDS_SRC})

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(EXE_NAME ${PROJECT_NAME}${CMAKE_PROJECT_VERSION})
add_executable(${EXE_NAME}
        ${IMGUI_SRC}
        ${IMGUI_BACKENDS_SRC}
        ${SRC}
)
target_include_directories(${EXE_NAME} PRIVATE
        ${GLEW_HEAD}
        ${GLFW_HEAD}
        ${IMGUI_HEAD}
        ${IMGUI_BACKENDS_HEAD}
)
target_link_libraries(${EXE_NAME} PRIVATE
        ${LIB_GLFW_x64}
        ${LIB_GLEW_x64}
        ${OPENGL_LIBRARIES}
)

