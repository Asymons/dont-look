add_executable(dont-look main.cpp DLWorker.cpp DLFaceCountService.cpp )
target_link_libraries(dont-look ${OpenCV_LIBS} )

