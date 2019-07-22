#include "../SimpleArtFunctions.h"
#include <iostream>
#include <deque>

extern config MainConfig;
void chooseInstrument(std::deque <cv::Mat> & buffer, int x, int y)
{
    switch (MainConfig.get_instrument_num())
    {

        case N_DEFAULT_BRUSH:
            defaultBrush(buffer.front(), x, y);
            break;
        case N_CIRCLE_BRUSH:
            circleBrush(buffer.front(), x, y);
            break;
        case N_LINE:
            line(buffer, x, y);
            break;
        case N_BUCKET:
            bucket(buffer.front(), x, y);
            break;
        case N_TRUE_LINE:
            true_line(buffer, x, y);
            break;
        case N_PIPETKA:
            pipette(buffer.front(), x, y);
            break;
        case N_UNDO:
            if(!MainConfig.get_isClicked())
            {
                step_back(buffer);
                MainConfig.set_isClicked(true);
            }
            break;
        case N_NOTHING:
            break;
        default:
            defaultBrush(buffer.front(), x, y);
            break;
    }
}