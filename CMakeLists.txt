cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(NAME VulkanDemo)

project(${NAME})

find_package(Vulkan REQUIRED)

include_directories(src)

add_subdirectory("lib/SDL2-2.0.9/") # SDL is only for examples.
include_directories("${SDL2_DIR}/include/")

file(GLOB SOURCE src/*.cpp )
add_executable(${NAME} ${SOURCE})

target_include_directories(${NAME} PRIVATE Vulkan::Vulkan)
target_link_libraries(${NAME} Vulkan::Vulkan)
target_link_libraries(${NAME} SDL2 SDL2main)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out")
set_target_properties( ${NAME}
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
)

# force sdl dlls to the same directory
set_target_properties( SDL2
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
)

