cmake_minimum_required(VERSION 3.10)

# project name
project("pi_ramanujan_boost")

# add the executable
add_executable("${PROJECT_NAME}" "src/main.cpp")
target_include_directories("${PROJECT_NAME}" PUBLIC "D:\\SDKs\\Boost\\1_76_0")