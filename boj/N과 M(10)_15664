#include <iostream>
#include <algorithm>

using namespace std;

int N, M, p[8], a[8];
bool used[8];

void solve(int d, int idx) {
	if (d == M) {
		for (int i = 0; i < d; i++) printf("%d ", p[i]);
		printf("\n");
		return;
	}
	int pv = 0;
	for (int i = idx; i < N; i++) {
		if (!used[i] && a[i] != pv) {
			used[i] = true;
			p[d] = a[i];
			solve(d + 1, i);
			used[i] = false;
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
