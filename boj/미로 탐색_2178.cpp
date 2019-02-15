#include <cstdio>
#include <queue>
int map[101][101], N, M,
dr[4] = { 0, 0, -1, 1 },
dc[4] = { 1, -1, 0, 0 };
void bfs() {
	int cnt = 2;
	std::queue<std::pair<int, int>> q; q.push({ 1, 1 });
	
	map[1][1] = cnt;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int r = q.front().first;
			int c = q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if(1 <= nr && nr <= N && 1 <= nc && nc <= M)
					if (map[nr][nc] == 1) {
						map[nr][nc] = cnt;
						q.push({ nr, nc });
					}
			}
		}
		cnt++;
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) scanf("%1d", &map[i][j]);

	bfs();
	printf("%d", map[N][M]);
	return 0;
}