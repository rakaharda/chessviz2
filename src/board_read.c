#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void boardread (int *board){
	char c;
	bool attack=false;
	short int cell1, cell2;
	FILE *input = fopen ("input.txt", "r");
	if (input==NULL) {printf ("error opening file(2)"); return;}
	c = fgetc(input);
	while (c!=EOF)
	{
        cell1=cell2=0;
        if (c==EOF) return;
		if (c<97||c>104) {
            printf ("Input error(1,1)!");
            return;
            }
        cell1+=c%97;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(1,2)!");
            return;
            }
        cell1+=(7-c%49)*8;
        c = fgetc(input);
        if (c!=45&&c!=120) {
            printf ("Input error(1,3)! ");
            return;
            }
        if (c==120) attack=true;
        c = fgetc(input);
        if (c<97||c>104) {
            printf ("Input error(2,1)!");
            return;
            }
        cell2+=c%97;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(2,2)!");
            return;
            }
        cell2+=(7-c%49)*8;
        if (!attack){
            if (board[cell1]!=12){
            printf ("Wrong move(1,1)!");
            return;
            }
            if (board[cell2]!=0){
            printf ("Wrong move(1,2)!");
            return;
            }
            if (cell1%8!=cell2%8){
            printf ("Wrong move(1,3)!");
            return;
            }
            if ((cell1-cell2)/8==1||(cell1-cell2)/8==2){
            board[cell1]=0;
            board[cell2]=12;
            } else {
            printf ("Wrong move(1,4)!");
            return;
            }
        } else {
        if (board[cell1]!=12){
            printf ("Wrong move(1,5)!");
            return;
            }
            if (board[cell2]==0||board[cell2]>6){
            printf ("Wrong move(1,6)!");
            return;
            }
            if (cell1%8!=cell2%8+1||cell1%8!=cell2%8-1){
            printf ("Wrong move(1,7)!");
            return;
            }
            if ((cell1-cell2)/8==1){
            board[cell1]=0;
            board[cell2]=12;
            } else {
            printf ("Wrong move(1,8)!");
            return;
            }
        } //end else
        if ((c=getc(input))!=' ') return;
        c=getc(input);
        cell1=cell2=0;
        if (c<97||c>104) {
            printf ("Input error(3,1)!");
            return;
            }
        cell1+=c%97;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(3,2)!");
            return;
            }
        cell1+=(7-c%49)*8;
        c = fgetc(input);
        if (c!=45&&c!=120) {
            printf ("Input error(3,3)!");
            return;
            }
        if (c==120) attack=true;
        c = fgetc(input);
        if (c<97||c>104) {
            printf ("Input error(4,1)!");
            return;
            }
        cell2+=c%97;
        c = fgetc(input);
        if (c<49||c>56) {
            printf ("Input error(4,2)!");
            return;
            }
        cell2+=(7-c%49)*8;
        if (!attack){
            if (board[cell1]!=6){
            printf ("Wrong move(2,1)! %d %d", cell1, board[cell1]);
            return;
            }
            if (board[cell2]!=0){
            printf ("Wrong move(2,2)!");
            return;
            }
            if (cell1%8!=cell2%8){
            printf ("Wrong move(2,3)!");
            return;
            }
            if ((cell2-cell1)/8==1||(cell2-cell1)/8==2){
            board[cell1]=0;
            board[cell2]=6;
            } else {
            printf ("Wrong move(2,4)!");
            return;
            }
        } else {
        if (board[cell1]!=6){
            printf ("Wrong move(2,5)!");
            return;
            }
            if (board[cell2]==0||board[cell2]<7){
            printf ("Wrong move(2,6)!");
            return;
            }
            if (cell1%8!=cell2%8+1||cell1%8!=cell2%8-1){
            printf ("Wrong move(2,7)!");
            return;
            }
            if ((cell1-cell2)/8==1){
            board[cell1]=0;
            board[cell2]=6;
            } else {
            printf ("Wrong move(2,8)!");
            return;
            }
        } //end else
        c = fgetc(input); c = fgetc(input);
	} //end while
}
