cmake_minimum_required(VERSION 2.8)
project( dont-look )
find_package( OpenCV REQUIRED )
find_package( Threads REQUIRED )
set (CMAKE_CXX_FLAGS "--std=c++11 -I/usr/local/opt/opencv/include ${CMAKE_CXX_FLAGS}")
subdirs(src)

