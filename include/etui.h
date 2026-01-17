#ifndef ETUI_H
#define ETUI_H

void save_cursor();
void restore_cursor();
void move_cursor(int x, int y);

void clear_screen();
void reset_canvas();

void set_termios(struct termios *x);
void enable_raw_mode();

void clean_up();
void setup();

#endif
