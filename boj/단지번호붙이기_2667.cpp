#include <cstdio>
#include <queue>
#include <algorithm>
int N, map[25][25], V = 9, dr[4] = { 0, 0, -1, 1 }, dc[4] = { 1, -1, 0, 0 };
int _cnt[25];

int bfs(int r, int c) {
	int cnt = 1;
	std::queue<std::pair<int, int>> q; q.push({ r, c });
	map[r][c] = V;
	while (!q.empty()) {
		r = q.front().first; c = q.front().second; q.pop();
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (0 <= nr && nr < N && 0 <= nc && nc < N) {
				if (map[nr][nc] == 1) {
					map[nr][nc] = V;
					q.push({ nr, nc });
					cnt++;
				}
			}
		}
	}
	return cnt;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%1d", &map[i][j]);

	int c = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				_cnt[c] = bfs(i, j);
				c++;
			}
		}
	}
	printf("%d\n", c);
	std::sort(_cnt, _cnt + c);
	for (int i = 0; i < c; i++) printf("%d\n", _cnt[i]);
	return 0;
}