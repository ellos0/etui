#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <unistd.h>
#include <termios.h>
//for raw mode

#include <sys/ioctl.h>
//for getting terminal size

#include "../include/etui.h"
#include "../include/window.h"

#define CLEAR_SCREEN "\033[2J"
#define CLEAR_LINE "\033[2K"

#define SAVE_CURSOR "\033[s"
#define RESTORE_CURSOR "\033[u"

//theres some other ansi escape codes in the program, but they aren't in one piece for easy usage.

//I'm bored and there's nothing like reinventing the wheel so we're rolling the graphics library ourselves.


struct termios original;

void save_cursor() {
  puts(SAVE_CURSOR);
}

void restore_cursor() {
  puts(RESTORE_CURSOR);
}

void move_cursor(int x, int y) {
  printf("\033[%d;%dH", y, x);
}

void clear_screen() {
  puts(CLEAR_SCREEN);
  fflush(stdout);
}

void reset_canvas() {
  clear_screen();
  move_cursor(0,0);
}

void set_termios(struct termios *x) {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, x);
}

void enable_raw_mode() {
  struct termios raw;

  tcgetattr(STDIN_FILENO, &raw);

  raw.c_lflag &= ~(ICANON | ECHO); //disable canonical mode and echo
  raw.c_cc[VMIN] = 1; //make it so it can read 1 or more chars
  raw.c_cc[VTIME] = 0; // no timeout for reading

  set_termios(&raw);
}

void clean_up() {
  set_termios(&original);
  reset_canvas();
}

void setup() {
  atexit(clean_up);

  tcgetattr(STDIN_FILENO, &original);
  enable_raw_mode();

  reset_canvas();
}

int main() {
  WindowStyle default_win_style = DEFAULT_WIN_STYLE
  setup();

  Window w = {2,2,20,8};
  box_window(&w, &default_win_style);
  w_move_cursor(&w,1,0);
  puts("test 1 2 3");

  w_place_wrap_text(&w,4,1, "Hello, world! testing 1 2 3 4 5 6 7 8 9 10");
  
  getc(stdin);
  
  return 0;
}
