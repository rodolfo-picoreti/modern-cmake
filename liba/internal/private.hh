
#pragma once

#include <iostream>
#include <opencv2/core.hpp>
#include "other.hh"

void print_mat() {
  cv::Mat mat = cv::Mat::ones(is::other(), 2, CV_32F);
  std::cout << "Mat = " << std::endl << " " << mat << std::endl;
}