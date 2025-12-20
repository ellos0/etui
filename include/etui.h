#ifndef ETUI_H
#define ETUI_H

typedef struct {
  char v; //vertical line char
  char h; //horizontal line char
  char tr; //top right corner char
  char tl; //top left corner char
  char br; //bottom right corner char
  char bl; //bottom left corner char
} WindowStyle;

WindowStyle default_win_style =  {'|', '-', '+', '+', '+', '+'};

typedef struct {
  int x_pos; //starting x position
  int y_pos; //starting y position
  int x_scale; //offset from starting x position as scale
  int y_scale; //offset from starting y position as scale
} Window;

void save_cursor();
void restore_cursor();
void move_cursor(int x, int y);

void clear_screen();
void reset_canvas();

void reset_raw_mode(struct termios *original);
void enable_raw_mode();

void clean_up();
void setup();

#endif
