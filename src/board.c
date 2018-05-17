#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int boardcheck (int *board, int cell1, int cell2, bool attack, int turn){
    if (!attack) if (board[cell2]!=0) return 1;
    if (cell1==cell2) return 1;
    if (board[cell1]==6||board[cell1]==12){
        if (!(turn%2)){
        if (!attack){
            if (cell1%8!=cell2%8){
                printf ("Wrong move(1,3)!");
                return 1;
            }
            if ((cell1-cell2)/8==1||(cell1-cell2)/8==2){
                return 0;
            } else {
                printf ("Wrong move(1,4)!");
                return 1;
            }
        } else {
            if (board[cell2]==0||board[cell2]>6){
                printf ("Wrong move(1,6)!");
                return 1;
            }
            if (cell1!=cell2+9&&cell1!=cell2+7){
                printf ("Wrong move(1,7)! %d %d", cell1, cell2);
                return 1;
            }
            if ((cell1-cell2)/8==1){
                return 0;
            } else {
                printf ("Wrong move(1,8)!");
                return 1;
            }
        }
        } //end else
        else {
        if (!attack){
            if (board[cell2]!=0){
                printf ("Wrong move(2,2)!");
                return 1;
            }
            if (cell1%8!=cell2%8){
                printf ("Wrong move(2,3)!");
                return 1;
            }
            if ((cell2-cell1)/8==1||(cell2-cell1)/8==2){
                return 0;
            } else {
                printf ("Wrong move(2,4)!");
                return 1;
            }
        } else {
            if (board[cell1]!=6){
                printf ("Wrong move(2,5)!");
                return 1;
            }
            if (board[cell2]==0||board[cell2]<7){
                printf ("Wrong move(2,6)!");
                return 1;
            }
            if (cell1!=cell2-9&&cell1!=cell2-7){
                printf ("Wrong move(2,7)! %d %d", cell1, cell2);
                return 1;
            }
            if ((cell1-cell2)/8==-1){
                return 0;
            } else {
                printf ("Wrong move(2,8)!");
                return 1;
            }
        }
    }
    }
    if (board[cell1]==3||board[cell1]==9){
        if (!(turn%2)&&board[cell1]!=9) return 1;
        if (!attack) {
            short int m, n;
            if (abs(cell1-cell2)%9==0) n=9; else n=7;
            if (cell1<cell2) m=1; else m=-1;
            if (abs(cell2-cell1)%n!=0) {printf (" %d %d %d", cell1, cell2, abs(cell2-cell1)%9);return 3;}
            for (int i=n; i<abs(cell2-cell1)+1; i+=n)
                if (board[cell1+(m*i)]!=0) return 4;
            return 0;
        }
    }
    return 99;
}
void boardmove (int *board, int cell1, int cell2) {
    board[cell2]=board[cell1];
    board[cell1]=0;
}
