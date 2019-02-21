#include <cstdio>
#include <queue>

using namespace std;

struct node {
	int r, c, type;
};

char map[51][51];
bool w_visit[51][51];
int dist[51][51];
const int dr[4] = { 0, 0, -1, 1 };
const int dc[4] = { 1, -1, 0, 0 };

int main() {
	int R, C, XR, XC; scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) scanf("%s", &map[i]);

	queue<node> q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			dist[i][j] = -1;
			if (map[i][j] == '*') {
				node a; a.r = i; a.c = j; a.type = 0;
				q.push(a);
			}
			if (map[i][j] == 'D') {
				XR = i; XC = j;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'S') {
				node a; a.r = i; a.c = j; a.type = 1;
				q.push(a);
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		node temp = q.front(); q.pop();
		int cr = temp.r;
		int cc = temp.c;
		int type = temp.type;

		for (int k = 0; k < 4; k++) {
			int nr = cr + dr[k];
			int nc = cc + dc[k];

			if (0 <= nr && nr < R && 0 <= nc && nc < C) {
				if (type == 0) {
					if (w_visit[nr][nc]) continue;
					if (map[nr][nc] == '.') {
						w_visit[nr][nc] = 1;
						map[nr][nc] = '*';
						node t; t.r = nr; t.c = nc; t.type = type;
						q.push(t);
					}
				}
				else {
					if (dist[nr][nc] == -1) {
						if (map[nr][nc] == '.') {	
							dist[nr][nc] = dist[cr][cc] + 1;
							node t; t.r = nr; t.c = nc; t.type = type;
							q.push(t);
						}
						else if (map[nr][nc] == 'D') {
							dist[nr][nc] = dist[cr][cc] + 1;
						}
					}
				}
			}
		}
	}

	printf("%d", dist[XR][XC]);
	return 0;
}