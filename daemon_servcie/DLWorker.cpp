//
// Created by Archer Zhang on 2016-12-03.
//

#include "DLWorker.h"

DLWorker::DLWorker(const cv::string& filename) {
    this->classifier.load(filename);
}

void DLWorker::proc(const cv::Mat input, cv::Mat &output) {

    cv::Mat canvas;

    input.copyTo(canvas);

    cv::cvtColor(input, output, CV_BGR2GRAY);
    cv::equalizeHist(output, output);
    this->classifier.detectMultiScale(output
                            , this->targets
                            , 1.1
                            , 2
                            , 0|CV_HAAR_SCALE_IMAGE
                            , cv::Size(100,100) );

    std::for_each(this->targets.begin(),
                  this->targets.end(),
                  [&](cv::Rect r){
                      this->targets.push_back(r);
                  });

    //std::cout << this->targets.size() << std::endl;

    std::for_each(this->targets.begin(),
                  this->targets.end(),
                  [&](cv::Rect& r){
                      cv::rectangle(
                              canvas
                              , cv::Point(r.x, r.y)
                              , cv::Point(r.x + r.width, r.y + r.height)
                              , cv::Scalar(0,255,0)
                              , 2);
                  });

    output = canvas;

    this->face_count = targets.size();
}

const uint32_t DLWorker::getFaceCount() const {
    return this->face_count;
}