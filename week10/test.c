#include <stdio.h>
#define N 0
#define NE 1
#define E 2
#define SE 3
#define S 4
#define SW 5
#define W 6
#define NW 7

typedef struct _Infor {
	int x;
	int y;
}Infor;

int move(int(*maze)[7], int(*mark)[7], int row, int col, Infor* stack, int* top) {//미로,갔던길체크,세로배열크기,가로배열크기,현재있는 위치,이동비용
	static int min = 999999999, count = 0;//이동비용 최소인 경로 갯수
	int R;
	for (R = 0; R < 8; R++) {//8방향 탐색
		if (stack->x == row - 2 && stack->y == col - 2 && R == 7) {//출구도착하면,8번중에1번
			if (min >= *top) {
				count++;
				if (min > *top) {
					count = 1;
					min = *top;
				}
			}
		}
		
		switch (R)//0~7까지 차례대로 북부터~동~남~서~북남까지 확인
		{
		case N:
			if (maze[stack->x - 1][stack->y] == 0 && mark[stack->x - 1][stack->y] == 0) {
				stack->x -= 1;//이동
				mark[stack->x][stack->y] = 1;//이동표시
				*top += 1;//이동비용증가
				move(maze, mark, row, col, stack, top);//다시 8방향 확인위해호출(재귀)
			}
			break;
		case NE:

			if (maze[stack->x - 1][stack->y + 1] == 0 && mark[stack->x - 1][stack->y + 1] == 0) {
				stack->x -= 1;
				stack->y += 1;
				mark[stack->x][stack->y] = 1;
				*top += 2;
				move(maze, mark, row, col, stack, top);
			}
			break;
		case E:
			if (maze[stack->x][stack->y + 1] == 0 && mark[stack->x][stack->y + 1] == 0) {
				stack->y += 1;
				mark[stack->x][stack->y] = 1;
				*top += 1;
				
				move(maze, mark, row, col, stack, top);
			}
			break;
		case SE:
			if (maze[stack->x + 1][stack->y + 1] == 0 && mark[stack->x + 1][stack->y + 1] == 0) {
				stack->x += 1;
				stack->y += 1;
				mark[stack->x][stack->y] = 1;
				*top += 2;
				
				move(maze, mark, row, col, stack, top);
			}
			break;
		case S:
			if (maze[stack->x + 1][stack->y] == 0 && mark[stack->x + 1][stack->y] == 0) {
				stack->x += 1;
				mark[stack->x][stack->y] = 1;
				*top += 1;
				
				move(maze, mark, row, col, stack, top);
			}
			break;
		case SW:
			if (maze[stack->x + 1][stack->y - 1] == 0 && mark[stack->x + 1][stack->y - 1] == 0) {
				stack->x += 1;
				stack->y -= 1;
				mark[stack->x][stack->y] = 1;
				*top += 2;
				
				move(maze, mark, row, col, stack, top);
			}
			break;
		case W:
			if (maze[stack->x][stack->y - 1] == 0 && mark[stack->x][stack->y - 1] == 0) {
				stack->y -= 1;
				mark[stack->x][stack->y] = 1;
				*top += 1;
				//printf("%d\n", *top);  <--------이부분부터 잘못된거 같습니다. 로직대로 따라가보면 *top값이 8이 나와야하는데 여기서부터 안나오네요ㅠㅠ
				move(maze, mark, row, col, stack, top);
			}
			break;
		case NW:
			if (maze[stack->x - 1][stack->y - 1] == 0 && mark[stack->x - 1][stack->y - 1] == 0) {
				stack->x -= 1;
				stack->y -= 1;
				mark[stack->x][stack->y] = 1;
				*top += 2;
				
				move(maze, mark, row, col, stack, top);
				
			}
			break;
		default:
			printf("switch문 오류");
		}

	}
	return count;
}

int main() {
	Infor mamory;

	int* top;
	int num1 = 0;
	top = &num1;

	int Maze[7][7] = {//1은벽,0은 길
		{1,1,1,1,1,1,1},
		{1,0,0,0,0,1,1},
		{1,1,1,0,1,1,1},
		{1,1,0,0,0,0,1},
		{1,1,0,1,1,1,1},
		{1,1,0,0,0,0,1},
		{1,1,1,1,1,1,1},
	};

	int Mark[7][7] = {
		{0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0}
	};

	mamory.x = 1;
	mamory.y = 1;
	int solution;

	solution = move(Maze, Mark, 7, 7, &mamory, top);
	
	printf("%d개", solution);
}
