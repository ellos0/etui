#include <stdio.h>
#include <stdlib.h>

#include "../include/etui.h"
#include "../include/window.h"

int main() {
  
  Window_Style default_win_style = DEFAULT_WIN_STYLE
  setup();

  Window w = {2,2,20,8};
  box_window(&w, &default_win_style);
  w_move_cursor(&w,1,0);
  puts("test window 1 2 3");

  w_place_wrap_text(&w,4,1, "Hello, world! testing 1 2 3 4 5 6 7 8 9 10");
  
  getc(stdin);
  
  return 0;
}
