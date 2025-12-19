#ifndef ETUI_H
#define ETUI_H

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
