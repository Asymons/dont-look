//
// Created by Archer Zhang on 2016-12-03.
//

#include "DLWorker.h"

DLWorker::DLWorker() {
    this->classifier.load(FACE_FILE);
}

void DLWorker::proc(const cv::Mat input, cv::Mat &output) {
    cv::cvtColor(input, output, CV_BGR2GRAY);
    
}