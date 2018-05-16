#include <stdio.h>
#include <stdlib.h>
#include "board_print_html.h"
#include "board_read.h"
#include "board.h"
#include <stdbool.h>
int main (){
FILE *index = fopen ("index.html", "w");
FILE *input = fopen ("input.txt", "r");
	if (input==NULL) {printf ("error opening file(2)"); return 1;}
int cell1, cell2, turn=0;
bool attack;
if (index==NULL) {printf ("error opening file");}
int board[64] = {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 12, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
int *p=board;
		while (!boardread (p, &cell1, &cell2, &attack, input)){
		if (!boardcheck(p, cell1, cell2, attack, turn)) boardmove (p, cell1, cell2); else printf (" %d",boardcheck(p, cell1, cell2, attack, turn));
		turn++;
		header (index);
		body (index, p);
		}
return 0;
}
