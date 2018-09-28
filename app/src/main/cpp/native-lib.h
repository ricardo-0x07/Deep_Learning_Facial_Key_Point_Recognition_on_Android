//
// Created by clive cadogan on 9/7/18.
//

#ifndef COMPUTERVISION2_NATIVE_LIB_H
#define COMPUTERVISION2_NATIVE_LIB_H

#include <jni.h>
#include "face-key-point-detect-lib.h"




extern "C" {

    JNIEXPORT void JNICALL Java_com_fieldmaven_android_computervision2_MainActivity_RecognizeFacialKeyPoints( JNIEnv *, jobject,
                                                      jlong imgAddr );

}


#endif //COMPUTERVISION2_NATIVE_LIB_H
