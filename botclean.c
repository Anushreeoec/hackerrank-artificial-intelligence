#include<stdio.h> 
#include<string.h> 
 
typedef struct position { 
   int r; 
   int c; 
} position; 
 
position getNearestDirt(char board[][5]); 
 
void next_move(int posr, int posc, char board[5][5]) { 
    if (board[posr][posc] == 'd') { 
       printf("CLEAN"); 
       return; 
    } 
    position i = getNearestDirt(board); 
 
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
 
position getNearestDirt(char board[][5]) { 
    position i; 
    i.r = 0; 
    i.c = 0; 
    for(int a=0; a<5; a++) { 
       for(int b=0; b<5; b++) { 
	       printf("%c\n", board[a][b]);
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
    int pos[2], i; 
    char board[5][5], line[6]; 
    scanf("%d", &pos[0]); 
    scanf("%d", &pos[1]); 
    for(i=0; i<5; i++) { 
        scanf("%s[^\\n]%*c", line); 
        strncpy(board[i], line, 5); 
    } 
    next_move(pos[0], pos[1], board); 
    return 0; 
}

