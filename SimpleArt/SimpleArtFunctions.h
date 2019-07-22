#ifndef RISOVAT_RISOVATFUNCTIONS_H
#define RISOVAT_RISOVATFUNCTIONS_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <deque>
#include "Palette/Mcolour.h"
#include "Utilities/Constants.h"
#include "SimpleArtClasses.h"
void generatePalitra(cv::Mat& palitraImg, Mcolour & mainColour);// generates palitra image
void chooseColour(cv::Mat& palitraImg, Mcolour & mainColour, int x, int y);//choose new colour with palitra click coordinates
void redrawMainColourInPalette(cv::Mat &paletteImg, Mcolour &mainColour);//draw square in Palitra window with main colour
void drawBarsInPalette(cv::Mat &paletteImg, Mcolour &MainColour);//draw colour lines in palitra window
void defaultBrush(cv::Mat & image, int x, int y);//default brush
void circleBrush(cv::Mat & image, int x, int y);//draw by empty circles
void chooseInstrument(std::deque <cv::Mat> & buffer, int x, int y);//choose instrument for action by click
void generateInstrumentsMenu(cv::Mat & image, instrument_button* instr_buttons);//generates instruments image
void chooseInstrumentButton(int x, int y);//choose instrument by click on button
void line(std::deque <cv::Mat> & buffer, int x, int y);//draw line with main colour and choosen brush
void bucket(cv::Mat & image, int x, int y);//fill area of one colour around click with main colour
bool check_colour(cv::Mat & image, int x, int y, Mcolour to_compare);//check if colout of point is equal user colour
void set_point_colour(cv::Mat & image, int x, int y, Mcolour to_set);//set colour at point
bool checkpoint(int x, int y);//check range
void change_colours(cv::Mat & image, int x, int y, Mcolour colour_to_change);//function for bucket
void wait_for_end_of_work(config & MainConfig);//wait unless job isn't finished
void step_back(std::deque<cv::Mat> &buffer);//undo action
void true_line(std::deque <cv::Mat> & buffer, int x, int y);//straight line
void pipette(cv::Mat &image, int x, int y);//get colour of pixel
#endif //RISOVAT_RISOVATFUNCTIONS_H
