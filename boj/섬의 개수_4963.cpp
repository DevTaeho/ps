#include <cstdio>
#include <queue>
int N, M, map[50][50], V = 9,
dr[8] = { 0,  0, -1,  1,  1, -1,  1, -1 },
dc[8] = { 1, -1,  0,  0,  1,  1, -1, -1 };

void bfs(int r, int c) {
	std::queue<std::pair<int, int>> q; q.push({ r, c });
	map[r][c] = V;
	while (!q.empty()) {
		r = q.front().first; c = q.front().second; q.pop();
		for (int k = 0; k < 8; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (0 <= nr && nr < N && 0 <= nc && nc < M) {
				if (map[nr][nc] == 1) {
					map[nr][nc] = V;
					q.push({ nr, nc });
				}
			}
		}
	}
}
int main() {
	while (1) {
		scanf("%d %d", &M, &N);

		if (N == 0 && M == 0) return 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);

		int c = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					c++;
				}
			}
		}
		printf("%d\n", c);
	}
	
	return 0;
}