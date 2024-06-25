# This is way too specific to my machine, but it works for now.

cmake_minimum_required(VERSION 3.5)
project(app VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

include_directories(/opt/homebrew/include ~/VulkanSDK/1.3.275.0/macOS/include)
link_directories(/opt/homebrew/lib ~/VulkanSDK/1.3.275.0/macOS/lib)

# Includes
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(Vulkan REQUIRED)

file (GLOB SRCS CONFIGURE_DEPENDS GLOB
	src/*.cpp
	src/*/*.cpp
	src/*/*/*.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} glfw glm Vulkan)
