#include <iostream>
#include <queue>

using namespace std;

char map[202][202];
int open_door[3][202][202];

const int dr[4] = { 0, 0, -1, 1 };
const int dc[4] = { 1, -1, 0, 0 };

const int not_visit = 1234;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TC;

	cin >> TC;
	while (TC--) {
		int m = 0, h, w;
		queue<pair<int, int>> man[3];

		for (int k = 0; k < 3; k++)
			for (int i = 0; i < 202; i++)
				for (int j = 0; j < 202; j++) open_door[k][i][j] = not_visit;

		cin >> h >> w;

		man[m].push(make_pair(0, 0)); open_door[m][0][0] = 0;
		m++;

		// get data
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$') {
					man[m].push(make_pair(i, j)); 
					open_door[m][i][j] = 0;
					m++;
				}
			}
		}

		// padding
		for (int i = 0; i <= w + 1; i++) {
			map[0][i] = '.';
			map[h + 1][i] = '.';
		}
		for (int i = 0; i <= h + 1; i++) {
			map[i][0] = '.';
			map[i][w + 1] = '.';
		}

		// bfs
		for (int i = 0; i < m; i++) {
			while (!man[i].empty()) {
				int r = man[i].front().first;
				int c = man[i].front().second;
				man[i].pop();

				for (int k = 0; k < 4; k++) {
					int nr = r + dr[k];
					int nc = c + dc[k];
					
					if (0 <= nr && nr <= h + 1 && 0 <= nc && nc <= w + 1 && map[nr][nc] != '*') {
						if (map[nr][nc] == '#') {
							if (open_door[i][nr][nc] > open_door[i][r][c] + 1) {
								open_door[i][nr][nc] = open_door[i][r][c] + 1;
								man[i].push(make_pair(nr, nc));
							}
						}
						else {
							if (open_door[i][nr][nc] > open_door[i][r][c]) {
								open_door[i][nr][nc] = open_door[i][r][c];
								man[i].push(make_pair(nr, nc));
							}
						}
					}
				}
			}
		}

		int min = 999999;
		
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (open_door[0][i][j] == -1 || open_door[1][i][j] == -1 || open_door[2][i][j] == -1) continue;
				int t = open_door[0][i][j] + open_door[1][i][j] + open_door[2][i][j];
				if (map[i][j] == '#') t -= 2;
				if (min > t) min = t;
			}
		}

		cout << min << '\n';
	}

	return 0;
}