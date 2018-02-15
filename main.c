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

}
