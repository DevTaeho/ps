#include <iostream>
#include <queue>
#include <set>
#include <memory.h>

using namespace std;

char map[102][102];

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		bool visited[102][102];
		
		int h, w, ans = 0;
		char ch[26];
		cin >> h >> w;

		//get
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}

		//padding
		for (int i = 0; i <= w + 1; i++) {
			map[0][i] = '.';
			map[h + 1][i] = '.';
		}
		for (int i = 0; i <= h + 1; i++) {
			map[i][0] = '.';
			map[i][w + 1] = '.';
		}

		//get token
		scanf("%s", ch);

		//insert token
		int i = 0;
		set<char> token;
		while (ch[i] != '\0') {
			token.insert(ch[i]);
			i++;
		}

		//bfs
		memset(visited, 0, sizeof(visited));
		queue<pair<int, int>> q; q.push(make_pair(0, 0)); visited[0][0] = 1;
		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second; q.pop();

			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];

				if (0 <= nr && nr <= h + 1 && 0 <= nc && nc <= w + 1) {
					if (!visited[nr][nc]) {
						if (map[nr][nc] == '.') {
							visited[nr][nc] = 1;
							q.push(make_pair(nr, nc));
						}
						else if ('A' <= map[nr][nc] && map[nr][nc] <= 'Z') {
							set<char>::iterator FindIter;
							FindIter = find(token.begin(), token.end(), (char)(map[nr][nc] + 32));
							if (FindIter != token.end()) {
								map[nr][nc] = '.';
								visited[nr][nc] = 1;
								q.push(make_pair(nr, nc));
							}
						}
						else if ('a' <= map[nr][nc] && map[nr][nc] <= 'z') {
							token.insert(map[nr][nc]);
							map[nr][nc] = '.';
							q.push(make_pair(nr, nc));
							memset(visited, 0, sizeof(visited));
						}
						else if (map[nr][nc] == '$') {
							ans++;
							visited[nr][nc] = 1;
							map[nr][nc] = '.';
							q.push(make_pair(nr, nc));
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}