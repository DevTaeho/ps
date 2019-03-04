#include <iostream>
#include <queue>

using namespace std;

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;

	while (tc--) {
		char map[102][102];
		int h, w, cnt = 0;
		char k[26];
		bool visited[102][102] = { 0, };
		bool keys[26] = { 0, };
		queue<pair<int, int>> locked_door[26];
		queue<pair<int, int >> q; q.push(make_pair(0, 0));

		cin >> h >> w;

		for (int i = 0; i <= w + 1; i++) {
			map[0][i] = '.';
			map[h + 1][i] = '.';
		}
		for (int i = 0; i <= h + 1; i++) {
			map[i][0] = '.';
			map[i][w + 1] = '.';
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}

		cin >> k;
		int i = 0;
		while (k[i] != '\0') {
			if (k[i] == '0') break;
			keys[(int)(k[i] - 'a')] = 1;
			i++;
		}

		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second; q.pop();

			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];

				int nch = (int)map[nr][nc];

				if (0 <= nr && nr <= h + 1 && 0 <= nc && nc <= w + 1 && map[nr][nc] != '*' && !visited[nr][nc]) {
					if (isupper(nch)) {
						if (keys[nch - 'A']) {
							map[nr][nc] = '.';
							visited[nr][nc] = 1;
							q.push(make_pair(nr, nc));
						}
						else {
							locked_door[nch - 'A'].push(make_pair(nr, nc));
						}
					}
					else if(islower(nch)){
						map[nr][nc] = '.';
						visited[nr][nc] = 1;
						q.push(make_pair(nr, nc));
						keys[nch - 'a'] = 1;
						while (!locked_door[nch - 'a'].empty()) {
							q.push(make_pair(locked_door[nch - 'a'].front().first, locked_door[nch - 'a'].front().second));
							map[locked_door[nch - 'a'].front().first][locked_door[nch - 'a'].front().second] = '.';
							visited[locked_door[nch - 'a'].front().first][locked_door[nch - 'a'].front().second] = 1;
							locked_door[nch - 'a'].pop();
						}
					}
					else if (map[nr][nc] == '$') {
						visited[nr][nc] = 1;
						map[nr][nc] = '.';
						q.push(make_pair(nr, nc));
						cnt++;
					}
					else {
						visited[nr][nc] = 1;
						q.push(make_pair(nr, nc));
					}
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}