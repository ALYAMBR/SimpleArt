#include "../SimpleArtFunctions.h"
extern Mcolour mainColour;
void defaultBrush(cv::Mat & image, int x, int y)
{
    for (int i = -BRUSH_SIZE; i < BRUSH_SIZE; ++i)
    {
        for (int j = -BRUSH_SIZE; j < BRUSH_SIZE; ++j)
        {
            if(checkpoint(x + j, y + i))
            {
                image.at<cv::Vec3b>(y + i, x + j)[0] = mainColour.get_blue();//blue
                image.at<cv::Vec3b>(y + i, x + j)[1] = mainColour.get_green();//green
                image.at<cv::Vec3b>(y + i, x + j)[2] = mainColour.get_red();//red
            }
        }
    }
}
void circleBrush(cv::Mat & image, int x, int y)
{
    for (int i = -BRUSH_SIZE; i < BRUSH_SIZE; ++i)
    {
        for (int j = -BRUSH_SIZE; j < BRUSH_SIZE; ++j)
        {
            if(i * i + j * j < (BRUSH_SIZE) * (BRUSH_SIZE) && i * i + j * j > (BRUSH_SIZE - 2) * (BRUSH_SIZE - 2) )
            {
                if(checkpoint(x + j, y + i))
                {
                    image.at<cv::Vec3b>(y + i, x + j)[0] = mainColour.get_blue();//blue
                    image.at<cv::Vec3b>(y + i, x + j)[1] = mainColour.get_green();//green
                    image.at<cv::Vec3b>(y + i, x + j)[2] = mainColour.get_red();//red
                }
            }
        }
    }
}