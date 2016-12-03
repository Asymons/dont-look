//
// Created by Archer Zhang on 2016-12-03.
//

#ifndef DONT_LOOK_DLWORKER_H
#define DONT_LOOK_DLWORKER_H

#include <opencv2/opencv.hpp>
#include <cstdint>

#define FACE_FILE "/usr/local/opt/opencv/share/OpenCV/lbpcascades/lbpcascade_frontalcatface.xml"

class DLWorker {

private:
    uint32_t face_count = 0;
    cv::CascadeClassifier classifier;

public:

    DLWorker();

    // Doing actual processing works
    // E.g. face count
    void proc(const cv::Mat input, cv::Mat& output);

};


#endif //DONT_LOOK_DLWORKER_H
