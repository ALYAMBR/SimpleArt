#include "../SimpleArtFunctions.h"
void redrawMainColourInPalette(cv::Mat &paletteImg, Mcolour &mainColour)
{
    for (int i = WINDOW_PALETTE_WIDTH / 2 - WINDOW_PALETTE_WIDTH / 10; i < WINDOW_PALETTE_WIDTH / 2 + WINDOW_PALETTE_WIDTH / 10; ++i)
    {
        for (int j = WINDOW_PALETTE_HEIGHT / 10; j < WINDOW_PALETTE_HEIGHT / 10 + 2 * WINDOW_PALETTE_WIDTH / 10; ++j)
        {
            paletteImg.at<cv::Vec3b>(j, i)[0] = mainColour.get_blue();
            paletteImg.at<cv::Vec3b>(j, i)[1] = mainColour.get_green();
            paletteImg.at<cv::Vec3b>(j, i)[2] = mainColour.get_red();
        }
    }
}