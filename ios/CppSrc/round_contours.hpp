//
//  round_contours.hpp
//  filters
//
//  Created by Piotr Suwała on 17/11/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

#ifndef round_contours_hpp
#define round_contours_hpp

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
cv::Mat getRoundContours(const std::string & path);

#endif /* round_contours_hpp */
