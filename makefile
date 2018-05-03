CFLAGS = -Wall -Werror 
OBJ = gcc -c $< -o $@  $(CFLAGS)-std=c99 

.PHONY: clean
all:bin build bin/deposit-calc 
bin/deposit-calc:  build/main.o build/board_print_html.o build/board_read.o
	g++ $^ -o $@ $(CFLAGS)

build/board_print_html.o: src/board_print_html.c src/board_print_html.h
	$(OBJ)

build/board_read.o: src/board_read.c src/board_read.h
	$(OBJ)

build/main.o: src/main.c
	$(OBJ)


bin: 
	mkdir bin
build:
	mkdir build

clean:
	rm build/*.o
	rm bin/*.exe
