//
// Created by clive cadogan on 9/23/18.
//

#ifndef COMPUTERVISION2_FACE_KEY_POINT_DETECT_LIB_H
#define COMPUTERVISION2_FACE_KEY_POINT_DETECT_LIB_H

#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include "face-key-point-detect-lib.h"


using namespace std;
using namespace cv;
using namespace dnn;

class FacialKeyPointsDetection {
    public:
        int process(Mat& frame);
        void detectAndDraw( Mat& img, CascadeClassifier& cascade,
                                 double scale, Net net );
    private:
        bool tryflip = false;
        double scale = 1.0;
        CascadeClassifier cascade;
        string cascadeName = "/sdcard/Download/data/haarcascade_frontalface_alt.xml";
        String weights = "/sdcard/Download/models/facialkeypoints_model_net.pb";
        Net net;
        Mat src;
        Mat dst;
};

#endif //COMPUTERVISION2_FACE_KEY_POINT_DETECT_LIB_H
