#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using std::cout;
int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_binary_value = 255;
Mat t_src, t_src_gray, t_dst;
static void Threshold_Demo( int, void* )
{
  /* 0: Binary
   1: Binary Inverted
   2: Threshold Truncated
   3: Threshold to Zero
   4: Threshold to Zero Inverted
   */
  threshold( t_src_gray, t_dst, threshold_value, max_binary_value, threshold_type );
}
cv::Mat getThreshold(const std::string & path)
{
  std::string photo = path == "" ? "/Users/meph1k/dev/filters/ios/CppSrc/Arwen-Return-of-the-King-arwen-undomiel-34589739-1000-646.jpg" : path;
  t_src = imread(photo, IMREAD_COLOR );
  if (t_src.empty())
  {
    cout << "Cannot read the image: " << std::endl;
    return t_src;
  }
  cvtColor( t_src, t_src_gray, COLOR_BGR2GRAY ); // Convert the image to Gray
  Threshold_Demo( 0, 0 ); // Call the function to initialize

  return t_dst;
}
