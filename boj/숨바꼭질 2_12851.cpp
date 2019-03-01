#include <cstdio>
#include <queue>
#include <memory.h>

using namespace std;
const int MAX = 100001;
int N, K, visit[MAX];
int r1 = MAX * 2, r2 = 0;
int main() {
	for (int i = 0; i < MAX; i++) visit[i] = -1;
	scanf("%d %d", &N, &K);
	queue<int> q; q.push(N);
	visit[N] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();

		if (x == K) {
			if (r1 >= visit[x]) r1 = visit[x], r2++;
			else break;
		}

		if (x + 1 < MAX)
			if (visit[x + 1] == -1 || (visit[x + 1] == visit[x] + 1)) {
				visit[x + 1] = visit[x] + 1;
				q.push(x + 1);
			}

		if (x - 1 >= 0)
			if (visit[x - 1] == -1 || (visit[x - 1] == visit[x] + 1)) {
				visit[x - 1] = visit[x] + 1;
				q.push(x - 1);
			}

		if (x * 2 < MAX)
			if (visit[2 * x] == -1 || (visit[2 * x] == visit[x] + 1)) {
				visit[2 * x] = visit[x] + 1;
				q.push(2 * x);
			}
	}
	printf("%d\n%d", r1, r2);
	return 0;
}