#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct position {
   int row;
   int column;
} position;

position checkPositionofBot(int n, char grid[][101]);
position checkPositionofPrincess(int n, char grid[][101]);

void displayPathtoPrincess(int n, char grid[101][101]) {
     position i = checkPositionofBot(n, grid);
     position j = checkPositionofPrincess(n, grid);

     signed int rowdiff;
     signed int coldiff;

     rowdiff = i.row - j.row;
     coldiff = i.column - j.column;

     printf("%d\n", rowdiff);
     printf("%d\n", coldiff);
     
     if (rowdiff < 0) {
         for(; rowdiff<0; ++rowdiff) {
	    printf("DOWN\n");
	 }
     } else {
         for(; rowdiff>0; --rowdiff) {
	    printf("UP\n");
	 }
     }

     if (coldiff < 0) {
         for(; coldiff<0; ++coldiff) {
	    printf("RIGHT\n");
	 }
     } else {
         for(; coldiff>0; --coldiff) {
	    printf("LEFT\n");
	 }
     }

     return;
}

position checkPositionofBot(int n, char grid[][101]) {
     position i;

     i.row = 0;
     j.column = 0;

     for (int a=0 ; a<n; a++) {
         for(int b=0; b<n; b++) {
	     if(grid[a][b] == 'm') {
	        i.row = a;
		i.column = b;
		return i;
	     }
	 }
     }

     return i;

}

position checkPositionofPrincess(int n, char grid[][101]) {
     position j;

     j.row = 0;
     j.column = 0;

     for(int a=0; a<n; a++) {
         for(int b=0; b<n; b++) {
	     if(grid[a][b] == 'p') {
	         j.row = a;
		 j.column = b;
		 return j;
	     }
	 }
     }

     return j;
}

int main() {
    int m;
    scanf("%d", &m);
    char grid[101][101];
    char line[101];

    for(int i=0; i<m; i++) {
       scanf("%s", line);
       strcpy(grid[i], line);
    }

    displayPathtoPrincess(m, grid);
    return 0;
}
