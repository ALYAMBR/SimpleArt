#include "../SimpleArtFunctions.h"
void generatePalitra(cv::Mat& palitraImg, Mcolour & mainColour)
{
    redrawMainColourInPalette(palitraImg, mainColour);
    drawBarsInPalette(palitraImg, mainColour);
}

