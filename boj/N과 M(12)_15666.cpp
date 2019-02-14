#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, a[8], p[8];

void solve(int d, int c) {
	if (d == M) {
		for (int i = 0; i < M; i++) printf("%d ", p[i]);
		printf("\n");
		return;
	}
	int pv = -1;
	for (int i = 0; i < N; i++) {
		if (c <= a[i] && pv != a[i]) {
			p[d] = a[i];
			solve(d + 1, a[i]);
			pv = a[i];
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	sort(a, a + N);
	solve(0, 0);
	return 0;
}
