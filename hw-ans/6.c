#include <stdio.h>
#include <stdlib.h>

#define N       0
#define NE      1
#define E       2
#define SE      3
#define S       4
#define SW      5
#define W       6
#define NW      7

typedef struct _Infor {
        int x;
        int y;
}Infor;

void mypush(Infor *stack, int *top, int row, int col) {
        (*top)++;
        stack[*top].x = row;
        stack[*top].y = col;
}

int move_rec(int **maze, int **mark, int row, int col, Infor *stack, int *top, int cost) {
        static int solution = 0;
        static int mincost = RAND_MAX;
        Infor *infor;
        int x, y;

        infor = stack + (*top);
        x = infor->x, y = infor->y;

        if (x == row - 2 && y == col - 2) {
                if ( cost < mincost ) {
                        mincost = cost;
                        solution = 1;
                } else if ( cost == mincost ) solution++;
        } else {
                for ( int dir=N; dir <= NW; dir++ ) {
                        int nx=x, ny=y;

                        if ( dir == NW || dir == N || dir == NE)      nx = x - 1;
                        else if ( dir == SE || dir == S || dir == SW) nx = x + 1;
                        if ( dir == NE || dir == E || dir == SE)      ny = y + 1;
                        else if ( dir == SW || dir == W || dir == NW) ny = y - 1;

                        if (mark[nx][ny] == 0 && maze[nx][ny] == 0) {
                                mark[nx][ny] = 1;
                                mypush(stack, top, nx, ny);

                                if ( dir == N || dir == E || dir == S || dir == S)
                                        solution = move_rec(maze, mark, row, col, stack, top, cost+1);
                                else
                                        solution = move_rec(maze, mark, row, col, stack, top, cost+2);
                        }
                }
        }
        mark[x][y] = 0;
        (*top)--;
        return solution;
}

int move(int **maze, int **mark, int row, int col, Infor *stack, int *top) {
        return move_rec(maze, mark, row, col, stack, top, 0);
}


//////// main /////////
int main(int argc, char *argv[]) {
        srandom(atoi(argv[4]));
        int row = atoi(argv[1]);
        int col = atoi(argv[2]);
        double th = atof(argv[3]);
        int **maze, **mark;
        int i, j, top=-1;

        maze = (int **)malloc(sizeof(int*)*row);
        mark = (int **)malloc(sizeof(int*)*row);
        for (i=0; i<row; i++ ) {
                maze[i] = (int *)malloc(sizeof(int)*col);
                mark[i] = (int *)malloc(sizeof(int)*col);
        }
        for (i=1; i<row-1; i++ ) {
                for (j=1; j<col-1; j++ ) {
                        if ( 1.0*random() / RAND_MAX < th ) maze[i][j] = 0;
                        else maze[i][j] = 1;
                }
        }
        for ( i=0; i<row; i++ ) maze[i][0] = maze[i][col-1] = 1;
        for ( i=0; i<col; i++ ) maze[0][i] = maze[row-1][i] = 1;
        maze[1][1] = maze[row-2][col-2] = 0;

        for (i=0; i<row; i++ )
                for (j=0; j<col; j++ ) mark[i][j] = 0;

        Infor *stack = (Infor *)malloc(sizeof(Infor)*row*col);

        mark[1][1] = 1;
        top = 0;
        stack[top].x = 1;
        stack[top].y = 1;

        int no = move(maze, mark, row, col, stack, &top);
        printf("%d\n", no);

        return 0;
}
