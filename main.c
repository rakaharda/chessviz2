<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
void header (FILE *outfile) {
FILE *source = fopen ("header.html", "r");
int c;
while ((c = fgetc(source)) != EOF) {
	fputc (c, outfile);
}
}

void body (FILE *outfile, int board[64]) {
fprintf (outfile, "<body>\n\t<table class=\"chessboard\">\n\t\t");
for (int i = 0; i<64; i++) {
if (i%8==0) fprintf (outfile, "<tr>");
if (board[i]==0) fprintf (outfile, "<td></td>\n");
else {
fprintf (outfile, "<td><span class=\"");
switch (board[i]) {
case 1: fprintf (outfile, "black rook"); break;
case 2: fprintf (outfile, "black knight"); break;
case 3: fprintf (outfile, "black bishop"); break;
case 4: fprintf (outfile, "black king"); break;
case 5: fprintf (outfile, "black queen"); break;
case 6: fprintf (outfile, "black pawn"); break;
case 7: fprintf (outfile, "white rook"); break;
case 8: fprintf (outfile, "white knight"); break;
case 9: fprintf (outfile, "white bishop"); break;
case 10: fprintf (outfile, "white king"); break;
case 11: fprintf (outfile, "white queen"); break;
case 12: fprintf (outfile, "white pawn"); break;
}
fprintf (outfile, "\"></span></td>\n");
}
if (i%8==7) fprintf (outfile, "</tr>");
}
fprintf (outfile, "</table></body></html>");
}
int main (){
FILE *index = fopen ("index.html", "w");
if (index==NULL) {printf ("error opening file");}
int chessboard[64] = {1, 2, 3, 4, 5, 3, 2, 1,
		   6, 6, 6, 6, 6, 6, 6, 6,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0,
		   12, 12, 12, 12, 12, 12, 12, 12,
		   7, 8, 9, 11, 10, 9, 8, 7};
		header (index);
		body (index, chessboard);			
}
=======
#include <stdio.h>
#include <stdlib.h>
void header (FILE *outfile) {
FILE *source = fopen ("header.html", "rb");
int c;
while ((c = fgetc(source)) != EOF) {
	fputc (c, outfile);
}
fclose (outfile);
}

void body (FILE *outfile, *board) {
fprintf (outfile, "<body>\n\t<table class=\"chessboard\">\n\t\t");
for (int i = 0; i<64; i++) {
if (i/8==0) fprintf (outfile, "<tr>");
if (*(board+i)=='e') fprintf (outfile, "<td></td>");
else {
fprintf (outfile, "<td><span class=\"");
switch (*(board+i)) {
case "br": fprintf (outfile, "black rook"); break;
case "bn": fprintf (outfile, "black knight"); break;
case "bb": fprintf (outfile, "black bishop"); break;
case "bk": fprintf (outfile, "black king"); break;
case "bq": fprintf (outfile, "black queen"); break;
case "bp": fprintf (outfile, "black pawn"); break;
case "wr": fprintf (outfile, "whire rook"); break;
case "wn": fprintf (outfile, "white knight"); break;
case "wb": fprintf (outfile, "white bishop"); break;
case "wk": fprintf (outfile, "white king"); break;
case "wq": fprintf (outfile, "white queen"); break;
case "wp": fprintf (outfile, "white pawn"); break;
}
fprintf (outfile, "\"></span></td>");
}
if (i/8==7) fprintf (outfile, "</tr>");
}
}
int main (){
FILE *index = fopen ("index.html", "wb");
char *chessboard = {"br", "bn", "bb", "bk", "bq", "bb", "bn", "br",
		   "bp", "bp", "bp", "bp", "bp", "bp", "bp", "bp",
		   'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
		   'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
		   'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
		   'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
		   "wp", "wp", "wp", "wp", "wp", "wp", "wp", "wp",
		   "wr", "wn", "wn", "wk", "wq", "wb", "wn", "wr"};
body (index, chessboard);			
}
>>>>>>> 7774761dc575d1ed28cd68a12c2c470f2467e24b
