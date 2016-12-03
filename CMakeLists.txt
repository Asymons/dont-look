cmake_minimum_required(VERSION 2.8)
project( dont-look )
find_package( OpenCV REQUIRED )
find_package( Boost REQUIRED system thread)
find_package( Threads REQUIRED )
include_directories( ${BOOST_INCLUDE_DIR} )
set (CMAKE_CXX_FLAGS "--std=c++11 -I/usr/local/opt/opencv/include ${CMAKE_CXX_FLAGS}")
subdirs(daemon_servcie)

