#ifndef RISOVAT_MCOLOUR_H
#define RISOVAT_MCOLOUR_H
#include <string>

#include <opencv2/core/hal/interface.h>

class Mcolour
{
    uchar red = 0;
    uchar green = 0;
    uchar blue = 0;
public:
    Mcolour(uchar ired, uchar igreen, uchar iblue)
    {
        red = ired;
        green = igreen;
        blue = iblue;
    }
    Mcolour(): red(0), green(0), blue(0){}
    Mcolour(Mcolour & source)
    {
        red = source.red;
        green = source.green;
        blue = source.blue;
    }
    uchar get_red() const;
    uchar get_green() const;
    uchar get_blue() const;
    void set_red(uchar sred);
    void set_green(uchar sgreen);
    void set_blue(uchar sblue);
    ~Mcolour() = default;
};


#endif //RISOVAT_MCOLOUR_H
