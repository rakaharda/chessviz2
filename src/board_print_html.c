#include <stdio.h>
#include <stdlib.h>

void header (FILE *outfile) {
FILE *source = fopen ("header.html", "r");
int c;
while ((c = fgetc(source)) != EOF) {
	fputc (c, outfile);
}
}

void body (FILE *outfile, int *board) {
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
