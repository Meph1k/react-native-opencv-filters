#ifndef canny_detector_hpp
#define canny_detector_hpp

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
cv::Mat getCannyImage(const std::string & path);


#endif /* canny_detector_hpp */
