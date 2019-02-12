bfs로 목적지로 갈 수 있는지 확인하는 문제다

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { 1, -1, 0, 0 };
const int MAZE_SIZE = 16;

bool visited[MAZE_SIZE][MAZE_SIZE];
int map[MAZE_SIZE][MAZE_SIZE];

void bfs(int start_x, int start_y) {
	queue<pair<int, int>> q; q.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nr = x + dx[k];
			int nc = y + dy[k];
			if (0 <= nr && nr < MAZE_SIZE && 0 <= nc && nc < MAZE_SIZE) {
				if (!visited[nr][nc] && map[nr][nc] != 1) {
					visited[nr][nc] = true;
					q.push({ nr, nc });
				}
			}
		}
	}
}

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		memset(visited, false, sizeof(visited));
		int testcase, r, c, endR, endC;
		int flag;
		scanf("%d", &testcase);

		for (int i = 0; i < MAZE_SIZE; i++) {
			for (int j = 0; j < MAZE_SIZE; j++) {
				scanf("%1d", &map[i][j]);

				if (map[i][j] == 2) {
					r = i;
					c = j;
				}

				if (map[i][j] == 3) {
					endR = i;
					endC = j;
				}
			}
		}

		bfs(r, c);

		visited[endR][endC] == true ? flag = 1 : flag = 0;

		printf("#%d %d\n", tc, flag);
	}

	return 0;
}
