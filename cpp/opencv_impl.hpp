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
        std::string get_canny(const std::string & path);
        std::string get_threshold(const std::string & path);
        std::string get_lines(const std::string & path);
        std::string get_contours(const std::string & path);
        std::string get_segments(const std::string & path);
        std::string get_round_contours(const std::string & path);
    };

}
