/*
test[i][j] means to find number of ways it can be done
classy problem
*/
#include <stdio.h>
#include <iostream>
#define M 10

using namespace std;

int maze[M][M], test[M][M], countpath = 0, n;

void path(int i, int j){

    if(i == n && j == n)
        countpath++;
    test[i][j] = 1;
    if((j + 1) <= n && test[i][j + 1] == 0 && maze[i][j + 1] == 0)
        path(i, j + 1);
    if((i + 1) <= n && test[i + 1][j] == 0 && maze[i + 1][j] == 0)
        path(i + 1, j);
    if((j - 1) >= 1 && test[i][j - 1] == 0 && maze[i][j - 1] == 0)
        path(i, j - 1);
    if((i - 1) >= 1 && test[i - 1][j] == 0 && maze[i - 1][j] == 0)
        path(i - 1, j);

    test[i][j] = 0;
    return;
}


int main(){
    int i, j;

    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            scanf("%d", &maze[i][j]);
            test[i][j] = 0;
        }
    }

    path(1, 1);
    printf("%d\n", countpath);
    return(0);
}
