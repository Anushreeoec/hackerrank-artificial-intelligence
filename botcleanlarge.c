#include<stdio.h> 
#include<string.h> 
 
typedef struct position { 
   int r; 
   int c; 
} position; 
 
position getNearestDirt(char board[][50], int row, int col); 
 
void next_move(int posr, int posc, char board[50][50], int row, int col) { 
    if (board[posr][posc] == 'd') { 
       printf("CLEAN"); 
       return; 
    } 
    position i = getNearestDirt(board, row, col); 
 
    int dr = posr - i.r; 
    int dc = posc - i.c; 

    if (dc < 0) { 
        printf("RIGHT"); 
        return; 
    } 
    else if (dc > 0) { 
        printf("LEFT"); 
        return; 
    } 
    else if (dr < 0) { 
        printf("DOWN"); 
        return; 
    } 
    else if (dr > 0) { 
        printf("UP"); 
        return; 
    } 
    else { 
        printf("CLEAN"); 
        return; 
    } 
    return; 
} 
 
position getNearestDirt(char board[][50], int row, int col) { 
    position i; 
    i.r = 0; 
    i.c = 0;
    for(int a=0; a<row; a++) { 
       for(int b=0; b<col; b++) {
           if(board[a][b] == 'd') { 
                i.r = a; 
                i.c = b;
                return i; 
           }
       } 
    } 
    return i; 
 
} 
 
int main(void) { 
    int pos[2], i, row, col;
    char board[50][50]; 
    scanf("%d", &pos[0]); 
    scanf("%d", &pos[1]);
    scanf("%d", &row);
    scanf("%d", &col);
    for(i=0; i<row; i++) { 
        scanf("%s[^\\n]%*c", board[i]); 
    } 
    next_move(pos[0], pos[1], board, row, col); 
    return 0; 
}

