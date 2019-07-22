#include "../SimpleArtFunctions.h"
#include <iostream>
void set_point_colour(cv::Mat & image, int x, int y, Mcolour to_set)
{
    image.at<cv::Vec3b>(y, x)[2] = to_set.get_red();
    image.at<cv::Vec3b>(y, x)[1] = to_set.get_green();
    image.at<cv::Vec3b>(y, x)[0] = to_set.get_blue();
}
bool check_colour(cv::Mat & image, int x, int y, Mcolour to_compare)
{
    if ((int)image.at<cv::Vec3b>(y, x)[2] != (int)to_compare.get_red())
        return false;
    if ((int)image.at<cv::Vec3b>(y, x)[1] != (int)to_compare.get_green())
        return false;
    return ((int)image.at<cv::Vec3b>(y, x)[0] == (int)to_compare.get_blue());//false if not equal, true if equal
}
bool checkpoint(int x, int y)//check range
{
    return !(x < 0 || x >= WINDOW_SIMPLE_ART_WIDTH || y < 0 || y >= WINDOW_SIMPLE_ART_HEIGHT);
}
void wait_for_end_of_work(config & MainConfig)
{
    while(MainConfig.get_isWorking())
        cvWaitKey(10);
}
void step_back(std::deque<cv::Mat> &buffer)
{
    buffer.pop_front();//delete first
    buffer.push_back( buffer.back().clone());//copy last
}