# Facial Keypoint Detection and Real-time Filtering Deployed to Android Mobile Device 
A boilerplate Computer Vision and Deep Learning Mobile app.

This is intended to provide way to prototype real-time Computer Vision and Deep Learning on Android Devices. The application is set up to perform Computer Vision and Deep Learning using native code for best performance. 


## Features
- Detects Faces and Identify Facial Key Points from Camera2 API with OpenCV Android SDK
- Performs Computer Vision and Deep Learning with native C++

## Setup
#### [Tested with OpenCV 3.4.2]
This project contains only the Android code necessary for performing native Computer Vision and Deep Learning Inference. In order to import and use OpenCV, users must perform a few steps, which are outlined below.

### Step 1 - Download the OpenCV Android SDK
You can obtain the latest version of the OpenCV Android SDK at https://github.com/opencv/opencv/releases, labelled *opencv-{VERSION}-android-sdk.zip* under Assets. After extracting the contents of the zip file, you should have a directory called *OpenCV-android-sdk*.

### Step 2 - Import the OpenCV Android SDK as a module in this project
Open the cloned version of this repo as a project in Android Studio. Then, click File -> New -> Import Module. Navigate to where you just extracted the OpenCV Android SDK files, and use *OpenCV-android-sdk/sdk/java* as the source directory for the import. Click Next, then click Finish, using the default import settings.

### Step 3 - Modify the OpenCV module's imported build.gradle
After the import completes, a new folder *openCVLibrary{VERSION_NUMBER}* is created in the root of the project. In this directory, there's a file called *build.gradle*, which you must modify in order to meet the SDK requirements of the application. Make the following changes:

#### In android
compileSdkVersion 14 -> compileSdkVersion27

#### In android.defaultConfig
minSdkVersion 8 -> minSdkVersion 23

targetSdkVersion 21 -> targetSdkVersion 27

### Step 4 - Copy native libs from OpenCV Android SDK
Create a new folder called *jniLibs* in the project's *app/src/main* folder. Then, copy everything in *OpenCV-android-sdk/sdk/native/libs* to the *jniLibs* directory you just created.

### Step 5 - Modify the CMakeLists.txt file
Lastly, you just need to update two strings in the CMakeList file to ensure your native libraries are linked correctly.
Open the project's *app/CMakeLists.txt* file. The first three lines should look like this:
```
# Update Path definitions
set(pathToProject /Users/jonathanreynolds/Documents/Projects/AndroidOpenCVCamera)
set(pathToOpenCv /Users/jonathanreynolds/Documents/Projects/OpenCV-android-sdk)
```

### Step 6 - Build and run
The app should build and run now. 

## Credits
 - (https://raw.githubusercontent.com/J0Nreynolds/AndroidOpenCVCamera/master/README.md)
 - (https://github.com/alexkarargyris/Caffe_OpenCV_Android_App)