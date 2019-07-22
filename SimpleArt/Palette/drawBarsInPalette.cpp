#include "../SimpleArtFunctions.h"
void drawBarsInPalette(cv::Mat &paletteImg, Mcolour &MainColour)
{
    auto d_WINDOW_PALETTE_WIDTH = static_cast<double> (WINDOW_PALETTE_WIDTH);
    for(int i = WINDOW_PALETTE_WIDTH / 10; i < WINDOW_PALETTE_WIDTH * 9 / 10; ++i)
    {
        for(int j = -PALETTE_COLOUR_BAR_HEIGHT; j <= PALETTE_COLOUR_BAR_HEIGHT; ++j)
        {
            paletteImg.at<cv::Vec3b>(WINDOW_PALETTE_HEIGHT * 5 / 8 + j, i)[0] = 0;
            paletteImg.at<cv::Vec3b>(WINDOW_PALETTE_HEIGHT * 5 / 8 + j, i)[1] = 0;
            paletteImg.at<cv::Vec3b>(WINDOW_PALETTE_HEIGHT * 5 / 8 + j, i)[2] = (255.0 / (d_WINDOW_PALETTE_WIDTH * 8.0 / 10.0 )) * (static_cast<double>(i) - d_WINDOW_PALETTE_WIDTH / 10.0);

            paletteImg.at<cv::Vec3b>(WINDOW_PALETTE_HEIGHT * 6 / 8 + j, i)[0] = 0;
            paletteImg.at<cv::Vec3b>(WINDOW_PALETTE_HEIGHT * 6 / 8 + j, i)[1] = (255.0 / (d_WINDOW_PALETTE_WIDTH * 8.0 / 10.0 )) * (static_cast<double>(i) - d_WINDOW_PALETTE_WIDTH / 10.0);
            paletteImg.at<cv::Vec3b>(WINDOW_PALETTE_HEIGHT * 6 / 8 + j, i)[2] = 0;

            paletteImg.at<cv::Vec3b>(WINDOW_PALETTE_HEIGHT * 7 / 8 + j, i)[0] = (255.0 / (d_WINDOW_PALETTE_WIDTH * 8.0 / 10.0 )) * (static_cast<double>(i) - d_WINDOW_PALETTE_WIDTH / 10.0);
            paletteImg.at<cv::Vec3b>(WINDOW_PALETTE_HEIGHT * 7 / 8 + j, i)[1] = 0;
            paletteImg.at<cv::Vec3b>(WINDOW_PALETTE_HEIGHT * 7 / 8 + j, i)[2] = 0;
        }
    }
}