#ifndef CONIOPLUS_H
#define CONIOPLUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if defined(linux) || defined(__APPLE__)

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define LIGHT_GRAY 37
#define DARK_GRAY 90
#define LIGHT_RED 91
#define LIGHT_GREEN 92
#define LIGHT_YELLOW 93
#define LIGHT_BLUE 94
#define LIGHT_MAGENTA 95
#define LIGHT_CYAN 96
#define WHITE 97

bool kbhit(); // check if any key is pressed
int getch(); // get the key which the user has pressed
#define Sleep(x) usleep((x) * 1000)

#else

#include <conio.h>
#include <windows.h>
#include <time.h>

#define BLACK 0
#define RED 4
#define GREEN 2
#define YELLOW 6
#define BLUE 1
#define MAGENTA 5
#define CYAN 3
#define LIGHT_GRAY 15
#define DARK_GRAY 8
#define LIGHT_RED 12
#define LIGHT_GREEN 10
#define LIGHT_YELLOW 14
#define LIGHT_BLUE 9
#define LIGHT_MAGENTA 13
#define LIGHT_CYAN 11
#define WHITE 7

#endif

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20

void move_cursor(int x, int y);
void hide_cursor();
void show_cursor();
void set_color(int foreground_color, int background_color); // set the foreground and background color
double get_time(); // get the time the program has run for
void clear_screen();
void clear_color(); // reset the output color

#endif
