add_executable(dont-look main.cpp DLWorker.cpp DLFaceCountService.cpp )
target_link_libraries(dont-look ${Boost_LIBRARIES})
target_link_libraries(dont-look ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(dont-look ${OpenCV_LIBS} )
