CFLAGS = -Wall -std=c99
OBJ = gcc -c $< -o $@  $(CFLAGS)

.PHONY: clean test
all:bin build bin/chessviz

test: bin/chessviz-test

bin/chessviz:  build/main.o build/board_print_html.o build/board_read.o build/board.o
	gcc $^ -o $@ $(CFLAGS)

bin/chessviz-test: build/main_test.o build/board_print_html.o build/board_read.o build/board.o
	gcc $^ -o $@ $(CFLAGS)

build/board_print_html.o: src/board_print_html.c src/board_print_html.h
	$(OBJ)

build/board_read.o: src/board_read.c src/board_read.h
	$(OBJ)

build/board.o: src/board.c src/board.h
	$(OBJ)

build/main.o: src/main.c
	$(OBJ)

build/main_test.o: test/main_test.c
	$(OBJ)

bin:
	mkdir bin
build:
	mkdir build

clean:
	rm build/*.o
	rm bin/*.exe
