#include <cstdio>
#include <queue>
#define MAX 8

using namespace std;

int N, K, tc, ans;
int map[MAX][MAX];
			      //하, 상, 우, 좌
const int dr[4] = { +1, -1, +0, -0 };
const int dc[4] = { +0, -0, +1, -1 };
bool visited[MAX][MAX];

void go(int r, int c, bool able, int step) {

	if (ans < step) ans = step;
	visited[r][c] = 1;

	int check = 0;
	for (int k = 0; k < 4; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
		if (visited[nr][nc]) continue;
		if (map[nr][nc] < map[r][c]) go(nr, nc, able, step + 1);
		else{
			if (able) {
				if (map[nr][nc] - K < map[r][c]) {
					int temp = map[nr][nc];
					map[nr][nc] = map[r][c] - 1;
					go(nr, nc, 0, step + 1);
					map[nr][nc] = temp;
				}
			}
		}
	}
	visited[r][c] = 0;
}

int main() {
	scanf("%d", &tc);

	for (int m = 1; m <= tc; m++) {
		scanf("%d %d", &N, &K);
		queue<pair<int, int>> q;
		ans = -1;
		int max = -1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] > max) max = map[i][j];
			}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max) q.push(make_pair(i, j));
			}

		while (!q.empty()) {
			int cur_r = q.front().first, cur_c = q.front().second;
			q.pop();
			go(cur_r, cur_c, 1, 1);
		}

		printf("#%d %d\n", m, ans);
	}
	
	return 0;
}
