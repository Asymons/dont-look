//
// Created by Archer Zhang on 2016-12-03.
//

#ifndef DONT_LOOK_DLWORKER_H
#define DONT_LOOK_DLWORKER_H

#include <opencv2/opencv.hpp>
#include <cstdint>
#include <vector>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#define FACE_FILE_MAC "/usr/local/opt/opencv/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml"

class DLWorker {

private:
    uint32_t face_count = 0;
    cv::CascadeClassifier classifier;
    std::vector<cv::Rect> targets;

public:

    DLWorker(const cv::string& filename);

    // Doing actual processing works
    // E.g. face count
    void proc(const cv::Mat input, cv::Mat& output);


    // get number of face being detected
    const uint32_t getFaceCount() const;

};


#endif //DONT_LOOK_DLWORKER_H
