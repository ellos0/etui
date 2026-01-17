#ifndef WINDOW_H
#define WINDOW_H

#define DEFAULT_WIN_STYLE {'|', '-', '+', '+', '+', '+'};

typedef struct {
  char v; //vertical line char
  char h; //horizontal line char
  char tr; //top right corner char
  char tl; //top left corner char
  char br; //bottom right corner char
  char bl; //bottom left corner char
} Window_Style;

typedef struct {
  int x_pos; //starting x position
  int y_pos; //starting y position
  int x_scale; //offset from starting x position as scale
  int y_scale; //offset from starting y position as scale
} Window;


void corners(Window *w, Window_Style *s);
void box_lines(Window *w, Window_Style *s);
void box_window(Window *w, Window_Style *s);
void w_move_cursor(Window *w, int x, int y);
void w_place_wrap_text(Window *w, int x, int y, char* text);
void w_place_wrap_text_rectangle(Window *w, int x, int y, char* text);

#endif 
