#include <cstdio>
#include <queue>

using namespace std;

struct node {
	int r, c, stones_break;
};

int maze[101][101];
int nums[101][101];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };
const int MMAX = 123456789;
int main() {
	int N, M;
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &maze[i][j]);
			nums[i][j] = MMAX;
		}
	}

	node x; x.r = 1; x.c = 1; x.stones_break = 0; nums[1][1] = 0;
	queue<node> q; q.push(x);
	int min = MMAX;
	
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			node t = q.front(); q.pop();
			int r = t.r;
			int c = t.c;
			int sts = t.stones_break;

			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];

				if (nr < 1 || nc < 1 || nr > N || nc > M) continue;

				if (maze[nr][nc] == 0) {
					if (sts < nums[nr][nc]) {
						nums[nr][nc] = sts;
						node t; t.r = nr; t.c = nc; t.stones_break = sts;
						q.push(t);
					}
				}
				else if (maze[nr][nc] == 1) {
					if (sts + 1 < nums[nr][nc]) {
						nums[nr][nc] = sts + 1;
						node t; t.r = nr; t.c = nc; t.stones_break = sts + 1;
						q.push(t);
					}
				}
			}
		}
	}

	printf("%d", nums[N][M]);

	return 0;
}