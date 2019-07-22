#include "../SimpleArtFunctions.h"
#include <fstream>
#include <string>
void generateInstrumentsMenu(cv::Mat & image, instrument_button* instr_buttons)
{
    std::ifstream fin ("icons/pictures_base.txt");
    std::string name_of_picture_file;
    cv::Mat picture_for_instrument_button;
    int x, y, num;
    for(int i = 0; i < NUM_OF_INSTRUMENTS; ++i)
    {
        fin >> name_of_picture_file;
        picture_for_instrument_button = cv::imread(name_of_picture_file, -1);//load unchanged image
        x =  WINDOW_INSTRUMENTS_BUTTON_SPACE_WIDTH * (i % NUMBER_OF_INSTR_BUTTONS_IN_STRING + 1) + (i % NUMBER_OF_INSTR_BUTTONS_IN_STRING) * WINDOW_INSTRUMENTS_BUTTON_WIDTH;
        if(x > WINDOW_INSTRUMENTS_WIDTH)
            throw std::logic_error("x > WINDOW INSTRUMENTS WIDTH");
        y = WINDOW_INSTRUMENTS_BUTTON_SPACE_HEIGHT * (i / NUMBER_OF_INSTR_BUTTONS_IN_STRING + 1) + (i / NUMBER_OF_INSTR_BUTTONS_IN_STRING) * WINDOW_INSTRUMENTS_BUTTON_HEIGHT;
        if(y > WINDOW_INSTRUMENTS_HEIGHT)
            throw std::logic_error("y > Window instruments height");
        num = i;
        instr_buttons[i].set_button_properties(num, x, y);
        instr_buttons[i].drawButtonImage(picture_for_instrument_button, image);
    }
    fin.close();
}