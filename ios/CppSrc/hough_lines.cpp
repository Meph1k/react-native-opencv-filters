//
//  hough_lines.cpp
//  filters
//
//  Created by Piotr Suwała on 17/11/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

#include "hough_lines.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;
using namespace std;
cv::Mat getLines(const std::string & path)
{
  // Declare the output variables
  Mat l_dst, cdst, cdstP;
  // Loads an image
  std::string photo = path == "" ? "/Users/meph1k/dev/filters/ios/CppSrc/wroclaw.jpg" : path;
  Mat src = imread(photo, IMREAD_GRAYSCALE );
  // Check if image is loaded fine
  if(src.empty()){
    printf(" Error opening image\n");
    return src;
  }
  // Edge detection
  Canny(src, l_dst, 50, 200, 3);
  // Copy edges to the images that will display the results in BGR
  cvtColor(l_dst, cdst, COLOR_GRAY2BGR);
  cdstP = cdst.clone();
  // Standard Hough Line Transform
  vector<Vec2f> lines; // will hold the results of the detection
  HoughLines(l_dst, lines, 1, CV_PI/180, 150, 0, 0 ); // runs the actual detection
  // Draw the lines
  for( size_t i = 0; i < lines.size(); i++ )
  {
    float rho = lines[i][0], theta = lines[i][1];
    Point pt1, pt2;
    double a = cos(theta), b = sin(theta);
    double x0 = a*rho, y0 = b*rho;
    pt1.x = cvRound(x0 + 1000*(-b));
    pt1.y = cvRound(y0 + 1000*(a));
    pt2.x = cvRound(x0 - 1000*(-b));
    pt2.y = cvRound(y0 - 1000*(a));
    line( cdst, pt1, pt2, Scalar(0,0,255), 3, LINE_AA);
  }
  // Probabilistic Line Transform
  vector<Vec4i> linesP; // will hold the results of the detection
  HoughLinesP(l_dst, linesP, 1, CV_PI/180, 50, 50, 10 ); // runs the actual detection
  // Draw the lines
  for( size_t i = 0; i < linesP.size(); i++ )
  {
    Vec4i l = linesP[i];
    line( cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
  }
  // Show results
//  imshow("Source", src);
//  imshow("Detected Lines (in red) - Standard Hough Line Transform", cdst);
//  imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);
  // Wait and Exit
  return cdstP;
}
