문제 URL ___ https://www.acmicpc.net/problem/14503

#include <iostream>

using namespace std;

		// 북  동  남  서
const int dx[4] = {-1, +0, +1, +0};
const int dy[4] = {+0, +1, +0, -1};

int N, M, r, c, d;
int map[51][51];
int res = 1;

const int CLEANED = 999;

int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	r = r + 1;
	c = c + 1;
	
	while (1) {
		bool cleaned = true;
		map[r][c] = CLEANED;

		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4; // 왼쪽 방향
			int nx = r + dx[d];
			int ny = c + dy[d];

			if (1 <= nx && nx <= N && 1 <= ny && ny <= M) {
				if (map[nx][ny] == 0) {
					cleaned = false;
					res++;
					r = nx;
					c = ny;
					break;
				}
			}
		}

		if (cleaned) {
			r = r - dx[d];
			c = c - dy[d];
			if (map[r][c] == 1) break;
		}
	}

	cout << res << '\n';

	return 0;
}
