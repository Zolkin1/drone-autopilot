#ifndef __JOYSTICK_H_INCLUDED__
#define __JOYSTICK_H_INCLUDED__

#include <ncurses.h>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Joystick {
    public:
        Joystick(WINDOW *win, bool springHorizontal, bool springVertical, bool useKeypad);
        void getMove();
        int *getSignal();

    private:
        int x, y, xMax, yMax, xBeg, yBeg, upStreak, downStreak, leftStreak, rightStreak;
        high_resolution_clock::time_point timeStart;
        double upClockStart, downClockStart, leftClockStart, rightClockStart;
        bool useKeypad, springHorizontal, springVertical;
        WINDOW *curwin;
        void clearScreenMem();
        void display();
        void up();
        void right();
        void down();
        void left();
        void center();
        double getTimeMillis();
};

#endif