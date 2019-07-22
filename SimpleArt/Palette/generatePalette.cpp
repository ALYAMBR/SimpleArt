#include "../SimpleArtFunctions.h"
void generatePalette(cv::Mat& paletteImg, Mcolour & mainColour)
{
    redrawMainColourInPalette(paletteImg, mainColour);
    drawBarsInPalette(paletteImg, mainColour);
}

