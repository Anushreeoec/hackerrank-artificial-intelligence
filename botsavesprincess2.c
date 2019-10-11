#include <stdio.h>
#include <string.h>
#include <math.h>

void nextMove(int n, int r, int c, char grid[101][101]){
    //logic here
    int a, b;
  for(int i=0; i<n; i++) {
     for(int j=0; j<n; j++) {
         if(grid[i][j] == 'p') {
	     a = i;
	     b = j;
	     break; 
	  }
      }
   }

  int rdiff = r - a;
  int cdiff = c - b;

  if (rdiff != 0) {
      if (rdiff < 0) {
         printf("DOWN");
         return;
       } 
      else {
         printf("UP");
         return;
       }
  }
  else if (cdiff != 0) {
     if (cdiff < 0) {
        printf("RIGHT");
        return;
     }
     else {
        printf("LEFT");
        return;
     }
  }

  return;


}

int main(void) {

    int n, r, c;

    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &c);

    char grid[101][101];
    
    for(int i=0; i<n; i++) {
        scanf("%s[^\n]%*c", grid[i]);
    }


    nextMove(n, r, c, grid);
    return 0;
}
