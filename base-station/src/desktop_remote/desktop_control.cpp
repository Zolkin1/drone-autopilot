#include <ncurses.h>
#include "joystick.h"

using namespace std;

const int JOYSTICK_BOX_HEIGHT = 25;
const int JOYSTICK_BOX_WIDTH = 50;

int main(int argc, char **argv) {  
    initscr();

    noecho();

    //create left joystick window
    int height, width, left_y, left_x;
    height = JOYSTICK_BOX_HEIGHT;
    width = JOYSTICK_BOX_WIDTH;
    left_y = left_x = 1;
    WINDOW *left_joystick_win = newwin(height, width, left_y, left_x);
    refresh();
    box(left_joystick_win, 0, 0);
    wrefresh(left_joystick_win);

    //create right joystick window
    int right_y, right_x;
    right_y = left_y;
    right_x = left_x + width + 4;
    WINDOW *right_joystick_win = newwin(height, width, right_y, right_x);
    refresh();
    box(right_joystick_win, 0, 0);
    wrefresh(right_joystick_win);

    Joystick *jLeft = new Joystick(left_joystick_win, true, false, false);
    Joystick *jRight = new Joystick(right_joystick_win, true, true, true);

    while(true) {
        jLeft->getMove();
        jRight->getMove();
    }

    endwin();

    return 0;
}