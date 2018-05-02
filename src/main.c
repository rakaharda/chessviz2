#include <stdio.h>
#include <stdlib.h>
#include "board_print_html.h"
#include "board_read.h"

int main (){
FILE *index = fopen ("index.html", "w");
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
		boardread (p);
		header (index);
		body (index, p);
return 0;
}
