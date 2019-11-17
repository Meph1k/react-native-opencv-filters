#pragma once

#include "opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

namespace opencv {

    class OpenCVImpl : public opencv::Opencv {

    public:

        // Constructor
        OpenCVImpl();

        // Our methods that return a string
        std::string get_canny();
        std::string get_threshold();
        std::string get_lines();
        std::string get_contours();
        std::string get_segments();
        std::string get_round_contours();
    };

}
