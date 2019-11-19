//
//  hough_lines.hpp
//  filters
//
//  Created by Piotr Suwała on 17/11/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

#ifndef hough_lines_hpp
#define hough_lines_hpp

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
cv::Mat getLines(const std::string & path);

#endif /* hough_lines_hpp */
