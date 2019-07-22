#include "../SimpleArtFunctions.h"

extern instrument_button* instr_buttons;
extern config MainConfig;
void chooseInstrumentButton(int x, int y)
{
    int localx = WINDOW_INSTRUMENTS_BUTTON_WIDTH + WINDOW_INSTRUMENTS_BUTTON_SPACE_WIDTH;
    int colnum = -1;
    for(int i = 0; i < NUMBER_OF_INSTR_BUTTONS_IN_STRING; ++i)
    {
        if(x <= localx && x >= localx - WINDOW_INSTRUMENTS_BUTTON_WIDTH)
        {
            colnum = i;
            break;
        }
        localx += WINDOW_INSTRUMENTS_BUTTON_WIDTH + WINDOW_INSTRUMENTS_BUTTON_SPACE_WIDTH;
    }
    int localy = WINDOW_INSTRUMENTS_BUTTON_HEIGHT + WINDOW_INSTRUMENTS_BUTTON_SPACE_HEIGHT;
    int rownum = -1;
    for(int i = 0; i < NUM_OF_INSTRUMENTS / NUMBER_OF_INSTR_BUTTONS_IN_STRING + (NUM_OF_INSTRUMENTS % NUMBER_OF_INSTR_BUTTONS_IN_STRING ? 1 : 0); ++i)
    {
        if(y <= localy && y >= localy - WINDOW_INSTRUMENTS_BUTTON_HEIGHT)
        {
            rownum = i;
            break;
        }
        localy += WINDOW_INSTRUMENTS_BUTTON_HEIGHT + WINDOW_INSTRUMENTS_BUTTON_SPACE_HEIGHT;
    }
    if(colnum == -1 || rownum == -1)
        return;
    int totalnum = colnum + rownum * NUMBER_OF_INSTR_BUTTONS_IN_STRING;
    MainConfig.set_instrument_num(instr_buttons[totalnum].get_numOfInstrument());
    if(MainConfig.get_instrument_num() <= N_CIRCLE_BRUSH)
        MainConfig.set_brush_num(MainConfig.get_instrument_num());
}