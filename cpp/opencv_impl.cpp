#include "opencv_impl.hpp"
#include "canny_detector.hpp"
#include "thresholding.hpp"
#include "hough_lines.hpp"
#include "contours.hpp"
#include "round_contours.hpp"
#include "segments.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <string>
#include "base64.hpp"

namespace opencv {

    std::shared_ptr<Opencv> Opencv::create() {
        return std::make_shared<OpenCVImpl>();
    }

    OpenCVImpl::OpenCVImpl() {

    }

    std::string OpenCVImpl::get_canny() {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getCannyImage(), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_threshold() {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getThreshold(), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_lines() {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getLines(), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_contours() {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getContours(), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_segments() {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getSegments(), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_round_contours() {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getRoundContours(), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
}
