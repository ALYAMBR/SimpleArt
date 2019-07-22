#include "../SimpleArtFunctions.h"
extern config MainConfig;
extern Mcolour mainColour;
void pipette(cv::Mat &image, int x, int y)
{
    mainColour.set_blue(image.at<cv::Vec3b>(y, x)[0]);
    mainColour.set_green(image.at<cv::Vec3b>(y, x)[1]);
    mainColour.set_red(image.at<cv::Vec3b>(y, x)[2]);
}
