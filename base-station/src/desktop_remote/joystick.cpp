#include "joystick.h"

//constants that change hold down behaviour
const int HOLD_TIME = 70; //Do not change
const int STREAK = 5;

Joystick::Joystick(WINDOW *win, bool springHorizontal, bool springVertical, bool useKeypad) {
    curwin = win;
    xBeg = 1;
    yBeg = 1;
    getmaxyx(curwin, yMax, xMax);
    x = (xMax + xBeg) / 2;
    y = (yMax + yBeg) / 2;
    this->useKeypad = useKeypad;
    this->springHorizontal = springHorizontal;
    this->springVertical = springVertical;
    keypad(curwin, useKeypad);
    //used for tracking long key presses
    timeStart = high_resolution_clock::now();
    upStreak = 0;
    downStreak = 0;
    leftStreak = 0;
    rightStreak = 0;
    //sets input mode to halfdelay
    halfdelay(1);
    display();
}

void Joystick::up() {
    clearScreenMem();
    double holdTime = getTimeMillis() - upClockStart;
    upClockStart = getTimeMillis();
    int stepNum = 1;
    if (holdTime < HOLD_TIME) upStreak++;
    else upStreak = 0;
    if (upStreak >= STREAK) stepNum = 2;
    if (y - stepNum > yBeg + 2) y -= stepNum;
    display();
}

void Joystick::down() {
    clearScreenMem();
    double holdTime = getTimeMillis() - downClockStart;
    downClockStart = getTimeMillis();
    int stepNum = 1;
    if (holdTime < HOLD_TIME) downStreak++;
    else downStreak = 0;
    if (downStreak >= STREAK) stepNum = 2;
    if (y + stepNum < yMax - 2) y += stepNum;
    display();
}

void Joystick::left() {
    clearScreenMem();
    double holdTime = getTimeMillis() - leftClockStart;
    leftClockStart = getTimeMillis();
    int stepNum = 1;
    if (holdTime < HOLD_TIME) leftStreak++;
    else leftStreak = 0;
    if (leftStreak >= STREAK) stepNum = 2;
    if (x - stepNum > xBeg + 2) x -= stepNum;
    display();
}

void Joystick::right() {
    clearScreenMem();
    double holdTime = getTimeMillis() - rightClockStart;
    rightClockStart = getTimeMillis();
    int stepNum = 1;
    if (holdTime < HOLD_TIME) rightStreak++;
    else rightStreak = 0;
    if (rightStreak >= STREAK) stepNum = 2;
    if (x + stepNum < xMax - 2) x += stepNum;
    display();
}

void Joystick::center() {
    if (springVertical == true) {
        clearScreenMem();
        y = (yMax + yBeg) / 2;
        display();
    }
    if (springHorizontal == true) {
        clearScreenMem();
        x = (xMax + xBeg) / 2;
        display();
    }
}

void Joystick::getMove() {
    int choice = wgetch(curwin);
    if (useKeypad) {
        if (choice == KEY_UP) up();
        else if (choice == KEY_DOWN) down();
        else if (choice == KEY_LEFT) left();
        else if (choice == KEY_RIGHT) right();
        else if (choice == '/') center();
    } else {
        if (choice == 'w') up();
        else if (choice == 's') down();
        else if (choice == 'a') left();
        else if (choice == 'd') right();
        else if (choice == 'q') center();
    }
}

void Joystick::clearScreenMem() {
    for (int i = 0; i < 3; i++) {
        mvwprintw(curwin, y - 2 + i, x - 2, "    ");
    }
}

void Joystick::display() {
    for (int i = 0; i < 3; i++) {
        mvwprintw(curwin, y - 2 + i, x - 2, "@@@@");
    }
    wrefresh(curwin);
}

double Joystick::getTimeMillis() {
    high_resolution_clock::time_point curTime = high_resolution_clock::now();
    duration<double, std::milli> time_span = curTime - timeStart;
    return time_span.count();
}