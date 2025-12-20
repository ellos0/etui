#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <termios.h>
//for raw mode

#include <sys/ioctl.h>
//for getting terminal size

#include "../include/etui.h"

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

void horizontal_line(int x, int y, int n) {
  move_cursor(x,y);
  for (int i=0;i<n;i++) {
    putc('-',stdout);
  }
  //prints - n number of times
}

void vertical_line(int x,int y, int n) {
  move_cursor(x,y);
  for (int i=0;i<=n;i++) {
    putc('|', stdout);
    move_cursor(x,y+i);
  }
  //moves down and prints | n number of times
}

void box_window(Window *x) {
  horizontal_line(x->x_pos ,x->y_pos ,x->x_scale);
  horizontal_line(x->x_pos ,x->y_pos + x->y_scale, x->x_scale);
  //im only going to act like i know why you need to add one to the yscale for this to work
  vertical_line(x->x_pos, x->y_pos, x->y_scale+1);
  vertical_line(x->x_pos+x->x_scale,x->y_pos, x->y_scale+1);
}

int main() {
  setup();

  Window w = {1,1,4,8};
  box_window(&w);
  
  fgetc(stdin);
  
  return 0;
}
