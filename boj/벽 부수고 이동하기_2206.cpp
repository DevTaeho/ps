#include <cstdio>
#include <queue>

using namespace std;

struct nd {
	int r, c, canBreak;
};

int map[1001][1001];
int dist[1001][1001][2];
const int dr[4] = { 0, 0, -1, 1 };
const int dc[4] = { 1, -1, 0, 0 };

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	nd a; a.r = 1; a.c = 1; a.canBreak = 1;
	queue<nd> q; q.push(a);
	dist[1][1][1] = 1;

	while (!q.empty()) {
		nd f = q.front(); q.pop();
		int r = f.r;
		int c = f.c;
		int canB = f.canBreak;

		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (nr < 1 || nc < 1 || nr > N || nc > M) continue;
			if (dist[nr][nc][canB] != 0) continue;
			if (map[nr][nc] == 0) {
				dist[nr][nc][canB] = dist[r][c][canB] + 1;
				nd t; t.r = nr; t.c = nc; t.canBreak = canB;
				q.push(t);
			}
			else {
				if (canB == 1) {
					nd t; t.r = nr; t.c = nc; t.canBreak = 0;
					q.push(t);
					dist[nr][nc][0] = dist[r][c][canB] + 1;
				}
			}
		}
	}

	int aa = dist[N][M][1], bb = dist[N][M][0];
	if (aa == 0 && bb == 0) {
		printf("-1");
	}
	else if (aa != 0 && bb == 0) {
		printf("%d", aa);
	}
	else if (aa == 0 && bb != 0) {
		printf("%d", bb);
	}
	else {
		aa > bb ? printf("%d", bb) : printf("%d", aa);
	}

	return 0;
}