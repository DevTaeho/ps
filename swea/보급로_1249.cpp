#include <cstdio>
#include <queue>
#include <memory.h>

using namespace std;

const int dr[4] = { +0, +0, +1, -1 };
const int dc[4] = { +1, -1, +0, +0 };

int main() {
	int testc;	scanf("%d", &testc);
	
	for (int tc = 1; tc <= testc; tc++) {
		int m, d[102][102], map[102][102]; scanf("%d", &m);
		for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) scanf("%1d", &map[i][j]);
		memset(d, -1, sizeof(d));
		queue<pair<int, int>> q; q.push(make_pair(1, 1)); d[1][1] = map[1][1];
		
		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second; q.pop();

			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];

				if (1 <= nr && nr <= m && 1 <= nc && nc <= m) {
					if (d[nr][nc] == -1) {
						d[nr][nc] = d[r][c] + map[nr][nc];
						q.push(make_pair(nr, nc));
					}
					else {
						if (d[nr][nc] > d[r][c] + map[nr][nc]) {
							d[nr][nc] = d[r][c] + map[nr][nc];
							q.push(make_pair(nr, nc));
						}
					}
				}
			}
		}

		printf("#%d %d\n", tc, d[m][m]);
	}

	return 0;
}