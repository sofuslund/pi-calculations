cmake_minimum_required(VERSION 3.15)

# set project name
project("pi_ramanujan_mpir")

# add executable
add_executable("${PROJECT_NAME}" "src/main.cpp")

# MPIR use a multi-threaded statically-linked runtime library so the project's runtime library must match
# we choose the runtime library to match the configuration (debug or release) with generator expressions
set_property(TARGET "${PROJECT_NAME}" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>") 

# add MPIR's include directory
target_include_directories("${PROJECT_NAME}" PUBLIC "D:/SDKs/MPIR/lib/x64/Debug")
# add MPIR's static libraries
target_link_libraries("${PROJECT_NAME}" 
	"D:/SDKs/MPIR/lib/x64/Debug/mpir.lib" 
	"D:/SDKs/MPIR/lib/x64/Debug/mpirxx.lib"
)
