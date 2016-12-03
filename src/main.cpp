//
// Created by Archer Zhang on 2016-12-03.
//

#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include "DLWorker.h"



using namespace std;
using namespace cv;

int main(int argc, char ** argv){


    VideoCapture cap(0);
    DLWorker w(FACE_FILE_MAC);


    if(!cap.open(0)){
        return 0;
    }

    while(1){
        Mat orig_frame;
        cap >> orig_frame;
        flip(orig_frame, orig_frame, 1);
        if(orig_frame.empty()) break;
        w.proc(orig_frame, orig_frame);
        imshow("Window", orig_frame);
        if(waitKey(1)  ==  27) break;

    }

    return 0;

}
