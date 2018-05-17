#define CTEST_MAIN
#include <stdio.h>
#include <stdlib.h>
#include "../thirdparty/ctest.h"
#include "../src/board.h"
#include <stdbool.h>

CTEST (move, correct_pawn1) {
int board[64] = {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 12, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
int *p=board;
int exp=0;
ASSERT_EQUAL (exp, boardcheck (p, 52, 44, false, 0));
}

CTEST (move, correct_pawn2) {
int board[64] = {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 12, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
int *p=board;
int exp=0;
ASSERT_EQUAL (exp, boardcheck (p, 52, 36, false, 0));
}

CTEST (move, incorrect_pawn1) {
int board[64] = {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 12, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
int *p=board;
int exp=0;
ASSERT_NOT_EQUAL (exp, boardcheck (p, 52, 43, false, 0));
}

CTEST (move, incorrect_pawn2) {
int board[64] = {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 12, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
int *p=board;
int exp=0;
ASSERT_NOT_EQUAL (exp, boardcheck (p, 52, 35, false, 0));
}

CTEST (move, correct_bishop) {
int board[64] = {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 0, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
int *p=board;
int exp=0;
ASSERT_EQUAL (exp, boardcheck (p, 58, 44, false, 0));
}

CTEST (move, incorrect_bishop) {
int board[64] = {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 12, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
int *p=board;
int exp=0;
ASSERT_NOT_EQUAL (exp, boardcheck (p, 58, 44, false, 0));
}

CTEST (attack, correct_pawn) {
int board[64] =   {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 6, 0, 0, 0, 0,
		   0, 0, 0, 0, 12, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 0, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
int *p=board;
int exp=0;
ASSERT_EQUAL (exp, boardcheck (p, 36, 27, true, 0));
}

CTEST (attack, incorrect_pawn) {
int board[64] = {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 6, 0, 0, 0, 0,
		   0, 0, 0, 0, 12, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 0, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
int *p=board;
int exp=0;
ASSERT_NOT_EQUAL (exp, boardcheck (p, 36, 29, true, 0));
}
int main(int argc, const char** argv) {
    return ctest_main(argc, argv);
}
