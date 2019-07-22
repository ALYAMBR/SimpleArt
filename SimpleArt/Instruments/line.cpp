#include "../SimpleArtFunctions.h"
extern config MainConfig;
void line(std::deque <cv::Mat> & buffer, int x, int y)
{
    if(MainConfig.get_oldy() <= -1 || MainConfig.get_oldx() <= -1)
        return;
    MainConfig.set_instrument_num(MainConfig.get_brush_num());
    int x1, x2, y1, y2;
    if(MainConfig.get_oldx() > x)
    {
        x1 = x;
        x2 = MainConfig.get_oldx();
        y1 = y;
        y2 = MainConfig.get_oldy();
    }
    else
        {
        x2 = x;
        x1 = MainConfig.get_oldx();
        y2 = y;
        y1 = MainConfig.get_oldy();
    }
    double k = static_cast<double>(y2 - y1) / static_cast<double>(x2 - x1);
    double b = static_cast<double>(x2 * y1 - x1 * y2) / static_cast<double>(x2 - x1);
    //the second cycle with the same actions but for inverted system of coordinates
    int tempy = 0;
    for(int i = x1; i <= x2; i += LINE_STEP_OF_BRUSH)
    {
        tempy = b + k * static_cast<double>(i);
        chooseInstrument(buffer, i, tempy);
    }
    if(MainConfig.get_oldy() > y)
    {
        x1 = x;
        x2 = MainConfig.get_oldx();
        y1 = y;
        y2 = MainConfig.get_oldy();
    }
    else
    {
        x2 = x;
        x1 = MainConfig.get_oldx();
        y2 = y;
        y1 = MainConfig.get_oldy();
    }
    k = static_cast<double>(x2 - x1) / static_cast<double>(y2 - y1);
    b = static_cast<double>(y2 * x1 - y1 * x2) / static_cast<double>(y2 - y1);
    int tempx = 0;
    for(int i = y1; i <= y2; i += LINE_STEP_OF_BRUSH)
    {
        tempx = b + k * static_cast<double>(i);
        chooseInstrument(buffer, tempx, i);
    }
    MainConfig.set_instrument_num(N_LINE);
}