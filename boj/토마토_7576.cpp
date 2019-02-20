#include <cstdio>
#include <queue>

using namespace std;

int VISIT = 99999;
int map[1001][1001];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };

int main() {
	int R, C;
	queue<pair<int, int>> q;
	scanf("%d %d", &C, &R);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				map[i][j] = VISIT;
			}
		}
	}

	int date = 0;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if (nc < 1 || nr < 1 || nr > R || nc > C) continue;
				if (map[nr][nc] == -1) continue;
				if (map[nr][nc] == VISIT) continue;
				map[nr][nc] = VISIT;
				q.push(make_pair(nr, nc));
			}
		}
		date++;
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", date - 1);
	return 0;
}