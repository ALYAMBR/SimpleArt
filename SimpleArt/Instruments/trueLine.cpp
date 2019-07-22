#include "../SimpleArtFunctions.h"
#include <iostream>
extern config MainConfig;
void true_line(std::deque <cv::Mat> & buffer, int x, int y)
{
    if(MainConfig.get_isMouseDown())
    {
        buffer.pop_front();
        buffer.push_front(buffer.front().clone());
        MainConfig.set_oldx(MainConfig.get_extra_oldx());
        MainConfig.set_oldy(MainConfig.get_extra_oldy());
        line(buffer, x, y);
        MainConfig.set_instrument_num(N_TRUE_LINE);
    }
}