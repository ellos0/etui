#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/etui.h"
#include "../include/window.h"

void horizontal_line(int x, int y, int n, char c) {
  move_cursor(x,y);
  for (int i=0;i<n;i++) {
    putc(c,stdout);
  }
  //prints - n number of times
}

void vertical_line(int x, int y, int n, char c) {
  move_cursor(x,y);
  for (int i=0;i<=n;i++) {
    putc(c, stdout);
    move_cursor(x,y+i);
  }
  //moves down and prints | n number of times
}

void corners(Window *w, Window_Style *s) {
  move_cursor(w->x_pos,w->y_pos);
  putc(s->tl, stdout); //top left corner
  move_cursor(w->x_pos+w->x_scale, w->y_pos);
  putc(s->tr, stdout); // top right corner
  move_cursor(w->x_pos, w->y_pos+w->y_scale);
  putc(s->bl, stdout); // bottom left corner
  move_cursor(w->x_pos+w->x_scale, w->y_pos+w->y_scale);
  putc(s->br, stdout); // bottom right corner
}

void box_lines(Window *w, Window_Style *s) {
  horizontal_line(w->x_pos ,w->y_pos ,w->x_scale, s->h);
  horizontal_line(w->x_pos ,w->y_pos + w->y_scale, w->x_scale, s->h);
  //im only going to act like i know why you need to add one to the yscale for this to work
  vertical_line(w->x_pos, w->y_pos, w->y_scale+1, s->v);
  vertical_line(w->x_pos+w->x_scale,w->y_pos, w->y_scale+1, s->v);
}

void box_window(Window *w, Window_Style *s) {
  box_lines(w, s);
  corners(w, s);
}

void w_move_cursor(Window *w, int x, int y) {
  move_cursor(w->x_pos + x,w->y_pos + y);
}

void w_place_wrap_text(Window *w, int x, int y, char* text) {
  w_move_cursor(w,x,y);
  int ci = 0; //character increment
  int ix = x; //ch x
  int iy = y; //ch y
  while (ci < strlen(text)) {
    if (ix >= w->x_scale) {
      iy++;
      ix = 1;
    }
    w_move_cursor(w,ix,iy);
    putc(text[ci], stdout);
    ix++;
    ci++;
  }
}

void w_place_wrap_text_rectangle(Window *w, int x, int y, char* text) {
  w_move_cursor(w,x,y);
  int ci = 0;
  int ix = x;
  int iy = y;
  while (ci < strlen(text)) {
    if (ix >= w->x_scale) {
      iy++;
      ix = x; // important part
    }
    w_move_cursor(w,ix,iy);
    putc(text[ci], stdout);
    ix++;
    ci++;
  }
}
