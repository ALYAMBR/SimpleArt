#include "../SimpleArtFunctions.h"
void chooseColour(cv::Mat& palitraImg, Mcolour & mainColour, int x, int y)
{
    auto d_WINDOW_PALITRA_WIDTH = static_cast<double>(WINDOW_PALETTE_WIDTH);
    auto d_x = static_cast<double>(x);
    if(y >= WINDOW_PALETTE_HEIGHT * 5 / 8 - PALETTE_COLOUR_BAR_HEIGHT && y <= WINDOW_PALETTE_HEIGHT * 5 / 8 + PALETTE_COLOUR_BAR_HEIGHT)//red bar
    {
        if(x >= WINDOW_PALETTE_WIDTH / 10 && x < WINDOW_PALETTE_WIDTH * 9 / 10)
        {
            mainColour.set_red((255.0 / (d_WINDOW_PALITRA_WIDTH * 8.0 / 10.0 )) * (d_x - d_WINDOW_PALITRA_WIDTH / 10.0));
        }
        return;
    }
    if(y >= WINDOW_PALETTE_HEIGHT * 6 / 8 - PALETTE_COLOUR_BAR_HEIGHT && y <= WINDOW_PALETTE_HEIGHT * 6 / 8 + PALETTE_COLOUR_BAR_HEIGHT)//green bar
    {
        if(x >= WINDOW_PALETTE_WIDTH / 10 && x < WINDOW_PALETTE_WIDTH * 9 / 10)
        {
            mainColour.set_green((255.0 / (d_WINDOW_PALITRA_WIDTH * 8.0 / 10.0 )) * (d_x - d_WINDOW_PALITRA_WIDTH / 10.0));
        }
        return;
    }
    if(y >= WINDOW_PALETTE_HEIGHT * 7 / 8 - PALETTE_COLOUR_BAR_HEIGHT && y <= WINDOW_PALETTE_HEIGHT * 7 / 8 + PALETTE_COLOUR_BAR_HEIGHT)//blue bar
    {
        if(x >= WINDOW_PALETTE_WIDTH / 10 && x < WINDOW_PALETTE_WIDTH * 9 / 10)
        {
            mainColour.set_blue((255.0 / (d_WINDOW_PALITRA_WIDTH * 8.0 / 10.0 )) * (d_x - d_WINDOW_PALITRA_WIDTH / 10.0));
        }
        return;
    }
}