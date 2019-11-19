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

    std::string OpenCVImpl::get_canny(const std::string & path) {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getCannyImage(path), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_threshold(const std::string & path) {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getThreshold(path), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_lines(const std::string & path) {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getLines(path), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_contours(const std::string & path) {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getContours(path), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_segments(const std::string & path) {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getSegments(path), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
  
    std::string OpenCVImpl::get_round_contours(const std::string & path) {
      std::vector<uchar> buf;
      cv::imencode(".jpg", getRoundContours(path), buf);
      auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
      std::string encoded = base64_encode(enc_msg, buf.size());
      return encoded;
    }
}
