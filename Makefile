CC := gcc
CFLAGS := -O1 -Wall -Wextra -g
LIB_DIR := $(HOME)/lib

SRC := src/etui.c src/window.c

.PHONY: clean

all: $(LIB_DIR)/libetui.so

#dynamic lib
$(LIB_DIR)/libetui.so:
	$(CC) $(CFLAGS) -fPIC -shared -o $(LIB_DIR)/libetui.so $(SRC)

eg: bin/hello

bin/hello: eg/hello.c $(LIB_DIR)/libetui.so
	$(CC) $(CFLAGS) -o bin/hello eg/hello.c -L$(LIB_DIR) -letui -Iinclude

clean:
	rm -rf bin
	mkdir bin
	rm $(LIB_DIR)/libetui.so
