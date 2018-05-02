#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void boardread (int *board){
	char c;
	bool attack=false;
	short int cell1=0, cell2=0;
	FILE *input = fopen ("input.txt", "r");
	c = fgetc(input);
	while (c!=EOF)
	{
		if (c<97||c>104) {
            printf ("Input error(1)!");
            return;
            }
        cell1+=c%98*8;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(2)!");
            return;
            }
        cell1+=c%50;
        c = fgetc(input);
        if (c!=45||c!=120) {
            printf ("Input error(3)!");
            return;
            }
        if (c==120) attack=true;
        c = fgetc(input);
        if (c<97||c>104) {
            printf ("Input error(1)!");
            return;
            }
        cell2+=c%98*8;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(2)!");
            return;
            }
        cell2+=c%50;
        if (!attack){
            if (board[cell1]!=6){
            printf ("Wrong move(1)!");
            return;
            }
            if (board[cell2]!=0){
            printf ("Wrong move(2)!");
            return;
            }
            if (cell1%8!=cell2%8){
            printf ("Wrong move(3)!");
            return;
            }
            if ((cell1-cell2)/8==1||(cell1-cell2)/8==2){
            board[cell1]=0;
            board[cell2]=6;
            } else {
            printf ("Wrong move(4)!");
            return;
            }
        } else {
        if (board[cell1]!=6){
            printf ("Wrong move(1)!");
            return;
            }
            if (board[cell2]==0||board[cell2]>6){
            printf ("Wrong move(2)!");
            return;
            }
            if (cell1%8!=cell2%8+1||cell1%8!=cell2%8-1){
            printf ("Wrong move(3)!");
            return;
            }
            if ((cell1-cell2)/8==1){
            board[cell1]=0;
            board[cell2]=6;
            } else {
            printf ("Wrong move(4)!");
            return;
            }
        } //end else
        if ((c=getc(input))!=' ') return;
        c=getc(input);
        if (c<97||c>104) {
            printf ("Input error(1)!");
            return;
            }
        cell1+=c%98*8;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(2)!");
            return;
            }
        cell1+=c%50;
        c = fgetc(input);
        if (c!=45||c!=120) {
            printf ("Input error(3)!");
            return;
            }
        if (c==120) attack=true;
        c = fgetc(input);
        if (c<97||c>104) {
            printf ("Input error(1)!");
            return;
            }
        cell2+=c%98*8;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(2)!");
            return;
            }
        cell2+=c%50;
        if (!attack){
            if (board[cell1]!=6){
            printf ("Wrong move(1)!");
            return;
            }
            if (board[cell2]!=0){
            printf ("Wrong move(2)!");
            return;
            }
            if (cell1%8!=cell2%8){
            printf ("Wrong move(3)!");
            return;
            }
            if ((cell1-cell2)/8==1||(cell1-cell2)/8==2){
            board[cell1]=0;
            board[cell2]=6;
            } else {
            printf ("Wrong move(4)!");
            return;
            }
        } else {
        if (board[cell1]!=6){
            printf ("Wrong move(1)!");
            return;
            }
            if (board[cell2]==0||board[cell2]>6){
            printf ("Wrong move(2)!");
            return;
            }
            if (cell1%8!=cell2%8+1||cell1%8!=cell2%8-1){
            printf ("Wrong move(3)!");
            return;
            }
            if ((cell1-cell2)/8==1){
            board[cell1]=0;
            board[cell2]=6;
            } else {
            printf ("Wrong move(4)!");
            return;
            }
        if ((c=getc(input))==12) c = fgetc(input);
        } //end else
	} //end while
}
