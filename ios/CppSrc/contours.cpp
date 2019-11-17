//
//  contours.cpp
//  filters
//
//  Created by Piotr Suwała on 17/11/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

#include "contours.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat c_src_gray;
int thresh = 100;
RNG rng(12345);
cv::Mat thresh_callback(int, void* );
cv::Mat getContours()
{
  Mat src = imread( "/Users/meph1k/dev/filters/ios/CppSrc/pole_mokotowskie.jpg" );
  if( src.empty() )
  {
    cout << "Could not open or find the image!\n" << endl;
    return src;
  }
  cvtColor( src, c_src_gray, COLOR_BGR2GRAY );
  blur( c_src_gray, c_src_gray, Size(3,3) );
//  const char* source_window = "Source";
//  namedWindow( source_window );
//  imshow( source_window, src );
//  const int max_thresh = 255;
//  createTrackbar( "Canny thresh:", source_window, &thresh, max_thresh, thresh_callback );
  return thresh_callback( 0, 0 );
}
cv::Mat thresh_callback(int, void* )
{
  Mat canny_output;
  Canny( c_src_gray, canny_output, thresh, thresh*2 );
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE );
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  for( size_t i = 0; i< contours.size(); i++ )
  {
    Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
    drawContours( drawing, contours, (int)i, color, 2, LINE_8, hierarchy, 0 );
  }
//  imshow( "Contours", drawing );
  return drawing;
}
