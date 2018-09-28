//
// Created by clive cadogan on 9/23/18.
//

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



int FacialKeyPointsDetection::process(Mat& frame) {

    net = readNetFromTensorflow(weights);

    if ( scale < 1 ) {
        scale = 1;
    }

    if ( !cascade.load( cascadeName ) ) {
        cerr << " error: Could not load classifier cascade" << endl;
        return -1;
    }

    if (frame.empty()) {
        cout << "Frame empty" << endl;
        return -1;
    }
    detectAndDraw( frame, cascade, scale, net );

    return 0;
}

void FacialKeyPointsDetection::detectAndDraw( Mat& img, CascadeClassifier& cascade,
                    double scale, Net net ) {
    double t = 0;
    vector<Rect> faces, faces2;
    const static Scalar colors[] = {
        Scalar(255,0,0),
        Scalar(255,128,0),
        Scalar(255,225,0),
        Scalar(0,225,0),
        Scalar(0,128,225),
        Scalar(0,225,225),
        Scalar(0,0,225),
        Scalar(255,0,225)
    };

    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY);
    double fx = 1/ scale;
    resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);
    equalizeHist( smallImg, smallImg );
    t = (double)getTickCount();
    cascade.detectMultiScale( smallImg, faces, 1.1, 2, 0, Size(30, 30) );

    t = (double)getTickCount() - t;
    printf( "detection time = %g ms\n", t*1000/getTickFrequency());

    for(size_t i = 0; i < faces.size(); i++) {
        Rect r = faces[i];
        vector<Rect> nestedObjects;
        Point center;
        Scalar color = colors[i/8];
        int radius;

        double aspect_ratio = (double)r.width/r.height;

        Mat crop_color_img = img( r );
        Mat crop_img;
        Mat resized_color_img;
        Mat resized_gray_img;
        Size originalSize = crop_color_img.size();
        Size inputSize(96, 96);
        float x_scale = originalSize.width/inputSize.width;
        float y_scale = originalSize.height/inputSize.height;
        resize(crop_color_img, resized_color_img, inputSize, 0, 0, CV_INTER_AREA);
        resized_color_img.convertTo(crop_img, CV_32F, 1.0/255);
        cvtColor(crop_img, resized_gray_img, COLOR_BGR2GRAY);
        Mat blob;
        blobFromImage(resized_gray_img, blob);
        net.setInput(blob);
        Mat output = net.forward();
        vector<float> values = output.row(0);
        for (size_t i = 0; i < output.cols; i+=2) {
            Point center;
            center.x = cvRound( ( values[i] * 48 + 48 ) );
            center.y = cvRound( ( values[i+1] * 48 + 48 ) );
            circle( resized_color_img, center, 1, color, 3, 8, 0 );
        }
        resize(resized_color_img, resized_color_img, originalSize, 0, 0, CV_INTER_LINEAR);
        resized_color_img.copyTo(img( r ));
    }
}
