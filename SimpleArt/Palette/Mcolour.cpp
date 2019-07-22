//
// Created by alyambr on 24.10.18.
//

#include "Mcolour.h"
uchar Mcolour::get_red() const
{
    return red;
}
uchar Mcolour::get_green() const
{
    return green;
}
uchar Mcolour::get_blue() const
{
    return blue;
}
void Mcolour::set_red(uchar sred)
{
    red = sred;
}
void Mcolour::set_green(uchar sgreen)
{
    green = sgreen;
}
void Mcolour::set_blue(uchar sblue)
{
    blue = sblue;
}