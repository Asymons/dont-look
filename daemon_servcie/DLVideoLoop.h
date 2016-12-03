//
// Created by Archer Zhang on 2016-12-03.
//

#ifndef DONT_LOOK_DLVIDEOLOOP_H
#define DONT_LOOK_DLVIDEOLOOP_H

#include "DLWorker.h"
#include "DLFaceCountService.h"
#include <future>
#include <functional>
#include <boost/smart_ptr.hpp>
#include <boost/thread.hpp>


using namespace std;
using namespace cv;

class DLVideoLoop {

public:
    static void run(){
        VideoCapture cap(0);
        DLWorker w(FACE_FILE);
        boost::asio::io_service io_service;
        DLFaceCountService service(io_service, 8888, &w);


        boost::thread thread(boost::bind(&boost::asio::io_service::run, &io_service));

        if(!cap.open(0)){
            return;
        }



        while(1){
            Mat orig_frame;
            cap >> orig_frame;
            flip(orig_frame, orig_frame, 1);
            if(orig_frame.empty()) break;
            w.proc(orig_frame, orig_frame);
            //imshow("Window", orig_frame);
            if(waitKey(1)  ==  27) break;

        }
    }

};


#endif //DONT_LOOK_DLVIDEOLOOP_H
