
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char ** argv){


    VideoCapture cap(0);

    if(!cap.open(0)){
        return 0;
    }

    while(1){
        Mat orig_frame;
        cap >> orig_frame;
        flip(orig_frame, orig_frame, 1);
        if(orig_frame.empty()) break;
        imshow("Window", orig_frame);
        if(waitKey(1)  ==  27) break;

    }

    return 0;

}
