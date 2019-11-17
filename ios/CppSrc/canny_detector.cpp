#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
Mat src, src_gray;
Mat dst, detected_edges;
int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;
const char* window_name = "Edge Map";
static cv::Mat CannyThreshold(int, void*)
{
  blur( src_gray, detected_edges, Size(3,3) );
  Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
  dst = Scalar::all(0);
  src.copyTo( dst, detected_edges);
  return dst;
}
cv::Mat getCannyImage()
{
  src = imread("/Users/meph1k/dev/filters/ios/CppSrc/fruits.jpg", IMREAD_COLOR );
  if( src.empty() )
  {
    std::cout << "Could not open or find the image!\n" << std::endl;
    return dst;
  }
  dst.create( src.size(), src.type() );
  cvtColor( src, src_gray, COLOR_BGR2GRAY );
  return CannyThreshold(0, 0);
}
