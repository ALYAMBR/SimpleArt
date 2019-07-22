#ifndef RISOVAT_RISOVATCLASSES_H
#define RISOVAT_RISOVATCLASSES_H

#include "Utilities/Constants.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Palette/Mcolour.h"
class instrument_button
{
    int x;//coords of image in instruments window
    int y;
    int numOfInstrument;//num of instrument
public:
    void drawButtonImage(cv::Mat& img, cv::Mat& mainImage)const
    {
        img.copyTo(mainImage.rowRange(y, y + WINDOW_INSTRUMENTS_BUTTON_HEIGHT).colRange(x, x + WINDOW_INSTRUMENTS_BUTTON_WIDTH));
    }
    const int get_numOfInstrument()const
    {
        return numOfInstrument;
    }
    void set_button_properties(int num_of_instr, int nx, int ny)
    {
        x = nx;
        y = ny;
        numOfInstrument = num_of_instr;
    }
};
class config
{
    int instrument_num = N_NOTHING;
    int brush_num = N_DEFAULT_BRUSH;
    int oldx = -1, oldy = -1, extra_oldx = -1, extra_oldy = -1;
    bool isMouseDown = false;
    bool isWorking = false;
    bool newLayerTime = true;
    bool isClicked = false;
public:
    int get_extra_oldx()
    {
        return extra_oldx;
    }
    int get_extra_oldy()
    {
        return extra_oldy;
    }
    void set_extra_oldx(int x)
    {
        extra_oldx = x;
    }
    void set_extra_oldy(int y)
    {
        extra_oldy = y;
    }
    bool get_isClicked()
    {
        return isClicked;
    }
    bool get_newLayerTime()
    {
        return newLayerTime;
    }
    bool get_isWorking()
    {
        return isWorking;
    }
    int get_instrument_num()
    {
        return instrument_num;
    }
    int get_brush_num()
    {
        return brush_num;
    }
    bool get_isMouseDown()
    {
        return isMouseDown;
    }
    int get_oldx()
    {
        return oldx;
    }
    int get_oldy()
    {
        return oldy;
    }
    void set_instrument_num(int new_instument_num)
    {
        instrument_num = new_instument_num;
    }
    void set_brush_num(int new_brush_num)
    {
        brush_num = new_brush_num;
    }
    void set_isMouseDown(bool new_state)
    {
        isMouseDown = new_state;
    }
    void set_oldx(int new_old_x)
    {
        oldx = new_old_x;
    }
    void set_oldy(int new_old_y)
    {
        oldy = new_old_y;
    }
    void set_isWorking(bool newStatus)
    {
        isWorking = newStatus;
    }
    void set_newLayerTime(bool newStatus)
    {
        newLayerTime = newStatus;
    }
    void set_isClicked(bool newStatus)
    {
        isClicked = newStatus;
    }
};

#endif //RISOVAT_RISOVATCLASSES_H
