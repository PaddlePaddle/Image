#ifndef DATAREADER_CPP_INCLUDE_IMAGE_UTIL_H
#define DATAREADER_CPP_INCLUDE_IMAGE_UTIL_H

#include <string>
#include <vector>

#include <opencv/cxcore.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace vis {

// error code for processed image
enum IMPROC_ERR_CODE_TYPE {
    IMPROC_OK = 0,
    IMPROC_INVALID_IMAGE = 2000,
    IMPROC_INVALID_PARAM = 2001,
    IMPROC_UNKOWN = 9999,
};

int read_image(const std::string &fname, std::vector<char> &buf);

int save_image(const cv::Mat &img, const std::string &fname);

IMPROC_ERR_CODE_TYPE decode_image(const std::vector<char> &img,
        cv::Mat &result, int mode = cv::IMREAD_UNCHANGED);

IMPROC_ERR_CODE_TYPE resize_image(const cv::Mat &img, const cv::Size &size,
        cv::Mat &result, int interpolation = cv::INTER_NEAREST,
        double fx = 0, double fy = 0);

IMPROC_ERR_CODE_TYPE crop_image(const cv::Mat &img, 
        const cv::Rect &rect, cv::Mat &result);

IMPROC_ERR_CODE_TYPE rotate_image(const cv::Mat &img,
        float angle, cv::Mat &result, int resample = cv::INTER_NEAREST);

IMPROC_ERR_CODE_TYPE flip_image(
        const cv::Mat &img, int flip_code, cv::Mat &result);

};//end of namespace 'vis'

#endif  //__IMAGE_UTIL_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */