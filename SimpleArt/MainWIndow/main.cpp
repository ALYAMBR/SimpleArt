#include <iostream>
#include <deque>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../SimpleArtClasses.h"
#include "../SimpleArtFunctions.h"
#include "../Utilities/Constants.h"


config MainConfig;
Mcolour mainColour = {175, 0, 175};
instrument_button* instr_buttons;

static void onMouseInstruments(const int event, const int x, const int y, int, void* param)
{
    wait_for_end_of_work(MainConfig);
    cv::Mat &image = *((cv::Mat*)(param));
    if(x < 0 || x >= WINDOW_INSTRUMENTS_WIDTH || y < 0 || y >= WINDOW_INSTRUMENTS_HEIGHT)
        return;
    MainConfig.set_isWorking(true);
    if(event == CV_EVENT_LBUTTONDOWN)
    {
        MainConfig.set_oldx(-1);
        MainConfig.set_oldy(-1);
        chooseInstrumentButton(x, y);
    }
    MainConfig.set_isWorking(false);
}
static void onMouseMain(const int event, const int x, const int y, int, void* param)
{
    wait_for_end_of_work(MainConfig);
    std::deque <cv::Mat> &buffer = *(( std::deque <cv::Mat>*)(param));//приводит void* к Mat*, затем разыменовывает и создаёт ссылку, т.к. static, то эта ссылка тут будет вечно
    if(x < 0 || x >= WINDOW_SIMPLE_ART_WIDTH || y < 0 || y >= WINDOW_SIMPLE_ART_HEIGHT)
        return;
    MainConfig.set_isWorking(true);
    if(!MainConfig.get_isMouseDown())
    {
        MainConfig.set_extra_oldx(x);
        MainConfig.set_extra_oldy(y);
    }
    if(MainConfig.get_isMouseDown())
    {
        chooseInstrument(buffer, x, y);
        MainConfig.set_oldx(x);
        MainConfig.set_oldy(y);
    }
    switch(event)
    {
        case CV_EVENT_LBUTTONDOWN:
            if(MainConfig.get_newLayerTime() && MainConfig.get_instrument_num() != N_UNDO)
            {
                buffer.pop_back();
                cv::Mat temp = buffer.front().clone();
                buffer.push_front(temp);
                MainConfig.set_newLayerTime(false);
            }
            MainConfig.set_isMouseDown(true);
            break;
        case CV_EVENT_LBUTTONUP:
            MainConfig.set_newLayerTime(true);
            MainConfig.set_isClicked(false);
            MainConfig.set_oldx(-1);
            MainConfig.set_oldy(-1);
            MainConfig.set_extra_oldx(-1);
            MainConfig.set_extra_oldy(-1);
            MainConfig.set_isMouseDown(false);
            break;
        default:
            break;
    }
    MainConfig.set_isWorking(false);
}
static void onMousePalitra(const int event, const int x, const int y, int, void* param)
{
    wait_for_end_of_work(MainConfig);
    cv::Mat &image = *((cv::Mat*)(param));
    if(x < 0 || x >= WINDOW_PALETTE_WIDTH || y < 0 || y >= WINDOW_PALETTE_HEIGHT)
        return;
    MainConfig.set_isWorking(true);
    if(event == CV_EVENT_LBUTTONDOWN)
    {
        MainConfig.set_oldx(-1);
        MainConfig.set_oldy(-1);
        chooseColour(image, mainColour, x, y);
        redrawMainColourInPalette(image, mainColour);
    }
    MainConfig.set_isWorking(false);
}
int main() {
    cv::namedWindow("SimpleArt", cv::WINDOW_GUI_NORMAL);
    cv::moveWindow("SimpleArt", MOVE_WINDOWS_X, MOVE_WINDOWS_Y);
    cv::setWindowProperty("SimpleArt", cv::WND_PROP_AUTOSIZE, CV_WINDOW_AUTOSIZE);
    std::deque <cv::Mat> main_image_buffer = {cv::Mat{WINDOW_SIMPLE_ART_HEIGHT, WINDOW_SIMPLE_ART_WIDTH, CV_8UC3, cv::Scalar(255, 255, 255)}};
    for(int i = 0; i < SIZE_OF_IMAGES_BUFFER - 1; ++i)//create buffer of SIZE_OF_IMAGES_BUFFER size
        main_image_buffer.push_front(cv::Mat{WINDOW_SIMPLE_ART_HEIGHT, WINDOW_SIMPLE_ART_WIDTH, CV_8UC3, cv::Scalar(255, 255, 255)});
    cv::setMouseCallback("SimpleArt", onMouseMain, &main_image_buffer);

    cv::namedWindow("Palitra", cv::WINDOW_GUI_NORMAL);
    cv::moveWindow("Palitra", MOVE_WINDOWS_X - WINDOW_PALETTE_WIDTH, MOVE_WINDOWS_Y);
    cv::setWindowProperty("Palitra", cv::WND_PROP_AUTOSIZE, CV_WINDOW_AUTOSIZE);
    cv:: Mat palitra(WINDOW_PALETTE_HEIGHT, WINDOW_PALETTE_WIDTH, CV_8UC3, cv::Scalar(255, 255, 255));//three colour lines - Red Green Blue]
    generatePalitra(palitra, mainColour);
    cv::setMouseCallback("Palitra", onMousePalitra, &palitra);

    cv::namedWindow("Instruments", cv::WINDOW_GUI_NORMAL);
    cv::moveWindow("Instruments", MOVE_WINDOWS_X - WINDOW_INSTRUMENTS_WIDTH, MOVE_WINDOWS_Y + WINDOW_SIMPLE_ART_HEIGHT - WINDOW_INSTRUMENTS_HEIGHT);
    cv::setWindowProperty("Instruments", cv::WND_PROP_AUTOSIZE, CV_WINDOW_AUTOSIZE);
    cv::Mat instruments(WINDOW_INSTRUMENTS_HEIGHT, WINDOW_INSTRUMENTS_WIDTH, CV_8UC3, cv::Scalar(255, 255, 255));//instuments like brushes, rectangles etc
    instr_buttons = new instrument_button [NUM_OF_INSTRUMENTS];
    generateInstrumentsMenu(instruments, instr_buttons);
    cv::setMouseCallback("Instruments", onMouseInstruments, &instruments);

    while(true)
    {

        cv::imshow("SimpleArt", main_image_buffer.front());
        redrawMainColourInPalette(palitra, mainColour);
        cv::imshow("Palitra", palitra);
        cv::imshow("Instruments", instruments);
        char c = cvWaitKey(1);
        if(c == 27)
            break;
    }
    delete [] instr_buttons;
    cv::destroyAllWindows();
    return 0;
}