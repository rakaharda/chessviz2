#include "board_read.h"

int boardread(int *board, int *cell1, int *cell2, bool *attack, FILE* input){
	char c;
    *attack=false;
	c = fgetc(input);
        *cell1=*cell2=0;
        if (c==EOF) return 1;
		if (c<97||c>104) {
            printf ("Input error(1,1)!");
            return 1;
            }
        *cell1+=c%97;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(1,2)!");
            return 1;
            }
        *cell1+=(7-c%49)*8;
        c = fgetc(input);
        if (c!=45&&c!=120) {
            printf ("Input error(1,3)! ");
            return 1;
            }
        if (c==120) *attack=true;
        c = fgetc(input);
        if (c<97||c>104) {
            printf ("Input error(2,1)!");
            return 1;
            }
        *cell2+=c%97;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(2,2)!");
            return 1;
            }
        *cell2+=(7-c%49)*8;
        c=fgetc(input);
        return 0;
}
