#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, prev_path[100001];
bool visit[100001];

int bfs() {
	queue<int> q; q.push(N);
	visit[N] = true;

	int cnt = 0;

	while (!q.empty()) {
		int sz = q.size();

		while (sz--) {
			int x = q.front(); q.pop();

			if (x == K) {
				return cnt;
			}

			if (x * 2 <= 100000 && !visit[x * 2]) {
				visit[x * 2] = 1;
				q.push(x * 2);
				prev_path[x * 2] = x;
			}

			if (x + 1 <= 100000 && !visit[x + 1]) {
				visit[x + 1] = 1;
				q.push(x + 1);
				prev_path[x + 1] = x; // x + 1의 이전 경로가 x임을 나타냄, prev_path[x + 1] = x
			}

			if (x - 1 >= 0 && !visit[x - 1]) {
				visit[x - 1] = 1;
				q.push(x - 1);
				prev_path[x - 1] = x;
			}
		}
		cnt++;
	}
}

int main() {
	scanf("%d %d", &N, &K);
	int ans = bfs();
	vector<int> l;
	printf("%d\n", ans);

	int ch = K;
	while (N != ch) {
		l.push_back(ch);
		ch = prev_path[ch];
	}
	l.push_back(ch);
	reverse(l.begin(), l.end());
	for (auto i : l) {
		printf("%d ", i);
	}
	return 0;
}