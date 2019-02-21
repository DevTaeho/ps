#include <cstdio>
#include <queue>

using namespace std;

struct nd {
	int r, c, h;
};

int R, C, H, dist[101][101][101], map[101][101][101];
const int dr[6] = { 0, 0, 1, -1, 0, 0 };
const int dc[6] = { 1, -1, 0, 0, 0, 0 };
const int dh[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
	scanf("%d %d %d", &C, &R, &H);
	queue<nd> q;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				dist[i][j][k] = -1;
				scanf("%d", &map[i][j][k]);
				if (map[i][j][k] == 1) {
					nd t; t.h = i; t.r = j; t.c = k;
					q.push(t);
					dist[i][j][k] = 1;
				}
			}
		}
	}

	int d = 0;
	while (!q.empty()) {
		int sz = q.size();

		while (sz--) {
			nd f = q.front(); q.pop();
			int h = f.h;
			int r = f.r;
			int c = f.c;

			for (int k = 0; k < 6; k++) {
				int nh = h + dh[k];
				int nr = r + dr[k];
				int nc = c + dc[k];

				if (1 <= nh && nh <= H && 1 <= nr && nr <= R && 1 <= nc && nc <= C) {
					if (dist[nh][nr][nc] == -1 && map[nh][nr][nc] == 0) {
						dist[nh][nr][nc] = dist[h][r][c] + 1;
						nd a; a.h = nh; a.r = nr; a.c = nc;
						q.push(a);
					}
				}
			}
		}
		d++;
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				printf("%d ", dist[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	
	return 0;
}