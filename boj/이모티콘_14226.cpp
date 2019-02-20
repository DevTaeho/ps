#include <cstdio>
#include <queue>

using namespace std;
bool visit[1001][1001];
int S;

void bfs() {
	queue<pair<int, int>> q; q.push(make_pair(1, 0));
	visit[1][0] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int cur = q.front().first;
			int cl = q.front().second;
			q.pop();

			if (cur == S) {
				printf("%d", cnt);
				return;
			}

			// º¹
			int c = cur;
			if (!visit[c][c]) {
				q.push(make_pair(cur, c));
				visit[c][c] = 1;
			}
			

			// ºÙ
			int l = cur + cl;
			if (cl != 0 && !visit[l][cl] && l <= 1000) {
				q.push(make_pair(l, cl));
				visit[l][cl] = 1;
			}

			// »è
			l = cur - 1;
			if (!visit[l][cl] && l > 1) {
				q.push(make_pair(l, cl));
				visit[l][cl] = 1;
			}
		}
		cnt++;
	}
}

int main() {
	scanf("%d", &S);
	bfs();
	return 0;
}