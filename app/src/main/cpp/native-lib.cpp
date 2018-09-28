#include <jni.h>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include "native-lib.h"
#include "face-key-point-detect-lib.cpp"

using namespace std;
using namespace cv;


extern "C" {

     JNIEXPORT void JNICALL Java_com_fieldmaven_android_computervision2_MainActivity_RecognizeFacialKeyPoints( JNIEnv*, jobject,
                                                                           jlong addrRgba) {
        FacialKeyPointsDetection detector;
        Mat& img = *(Mat*)addrRgba;
        detector.process(img);
    }

}