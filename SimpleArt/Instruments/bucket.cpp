#include "../SimpleArtFunctions.h"
#include <iostream>
extern config MainConfig;
extern Mcolour mainColour;
void bucket(cv::Mat & image, int x, int y)
{
    if(!checkpoint(x, y))
        return;
    Mcolour colour_to_change = {image.at<cv::Vec3b>(y, x)[2], image.at<cv::Vec3b>(y, x)[1], image.at<cv::Vec3b>(y, x)[0]};
    if(!check_colour(image, x, y, mainColour))
        change_colours(image, x, y, colour_to_change);
}
void change_colours(cv::Mat & image, int x, int y, Mcolour colour_to_change)
{
    bool something_happened = false;
    int i = 0;
    while(checkpoint(x - i, y) && check_colour(image, x - i, y, colour_to_change))
    {
        set_point_colour(image, x - i, y, mainColour);
        something_happened = true;
        ++i;
    }
    --i;
    int j = 1;
    while(checkpoint(x + j, y) && check_colour(image, x + j, y, colour_to_change))
    {
        set_point_colour(image, x + j, y, mainColour);
        something_happened = true;
        ++j;
    }
    --j;
    for(int k = x - i; k <= x + j; ++k)
    {
        if(checkpoint(k, y + 1) && check_colour(image, k, y + 1, colour_to_change))
            change_colours(image, k, y + 1, colour_to_change);
    }
    for(int k = x - i; k <= x + j; ++k)
    {
        if(checkpoint(k, y - 1) && check_colour(image, k, y - 1, colour_to_change))
            change_colours(image, k, y - 1, colour_to_change);
    }
    if(!something_happened)
        return;
}