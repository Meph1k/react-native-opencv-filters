//
//  round_contours.cpp
//  filters
//
//  Created by Piotr Suwała on 17/11/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

#include "round_contours.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat r_src_gray;
int r_thresh = 100;
RNG r_rng(12345);
cv::Mat r_thresh_callback(int, void* );
cv::Mat getRoundContours()
{
  Mat src = imread( "/Users/meph1k/dev/filters/ios/CppSrc/pole_mokotowskie.jpg" );
  if( src.empty() )
  {
    cout << "Could not open or find the image!\n" << endl;
    return src;
  }
  cvtColor( src, r_src_gray, COLOR_BGR2GRAY );
  blur( r_src_gray, r_src_gray, Size(3,3) );
//  const char* source_window = "Source";
//  namedWindow( source_window );
//  imshow( source_window, src );
//  const int max_thresh = 255;
//  createTrackbar( "Canny thresh:", source_window, &thresh, max_thresh, thresh_callback );
  return r_thresh_callback( 0, 0 );
}
cv::Mat r_thresh_callback(int, void* )
{
  Mat canny_output;
  Canny( r_src_gray, canny_output, r_thresh, r_thresh*2 );
  vector<vector<Point> > contours;
  findContours( canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
  vector<RotatedRect> minRect( contours.size() );
  vector<RotatedRect> minEllipse( contours.size() );
  for( size_t i = 0; i < contours.size(); i++ )
  {
    minRect[i] = minAreaRect( contours[i] );
    if( contours[i].size() > 5 )
    {
      minEllipse[i] = fitEllipse( contours[i] );
    }
  }
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  for( size_t i = 0; i< contours.size(); i++ )
  {
    Scalar color = Scalar( r_rng.uniform(0, 256), r_rng.uniform(0,256), r_rng.uniform(0,256) );
    // contour
    drawContours( drawing, contours, (int)i, color );
    // ellipse
    ellipse( drawing, minEllipse[i], color, 2 );
    // rotated rectangle
    Point2f rect_points[4];
    minRect[i].points( rect_points );
    for ( int j = 0; j < 4; j++ )
    {
      line( drawing, rect_points[j], rect_points[(j+1)%4], color );
    }
  }
  return drawing;
//  imshow( "Contours", drawing );
}
