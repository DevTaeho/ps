#include <iostream>
#include <algorithm>

using namespace std;

int N, M, a[8], p[8];

void solve(int d) {
	if (d == M) {
		for (int i = 0; i < d; i++) printf("%d ", p[i]);
		printf("\n");
		return;
	}

	int pv = -1;
	for (int i = 0; i < N; i++) {
		if(pv != a[i]){
			p[d] = a[i];
			solve(d + 1);
			pv = a[i];
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	sort(a, a + N);
	solve(0);
	return 0;
}
