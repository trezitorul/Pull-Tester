################################################################################
### Template code. Do not modify                                               #
                                                                              #
cmake_minimum_required (VERSION 3.0.0)                                         #
# Aside from cmake_minimum_required, this must be the first two lines          #
# of the file                                                                  #
file(TO_CMAKE_PATH $ENV{PROPWARE_PATH} PROPWARE_PATH)                          #
include(${PROPWARE_PATH}/CMakePropellerHeader.cmake)                           #
################################################################################

set(BOARD DEMOBOARD)
set(MODEL cmm)
set(COMMON_FLAGS "-Os")

project(PullTester C CXX)

create_simple_executable(${PROJECT_NAME} ${PROJECT_NAME})
