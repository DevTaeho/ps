#include <cstdio>
#include <queue>

using namespace std;
int N, K;
bool v[100001];
int bfs() {
	queue<int> q; q.push(N);
	int cnt = 0;

	while (!q.empty()) {
		int sz = q.size();
		
		while (sz--) {
			int x = q.front(); q.pop();

			v[x] = true;

			if (x == K) return cnt;

			int nx = x + 1;
			if (!v[nx] && nx <= 100000) {
				v[nx] = true;
				q.push(nx);
			}

			nx = x - 1;
			if (!v[nx] && 0 <= nx) {
				v[nx] = true;
				q.push(nx);
			}

			nx = x * 2;
			if (!v[nx] && nx <= 100000) {
				v[nx] = true;
				q.push(nx);
			}
		}
		cnt++;
	}
}
int main() {
	scanf("%d %d", &N, &K);
	printf("%d", bfs());
	return 0;
}