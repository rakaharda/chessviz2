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
int main (){

}
