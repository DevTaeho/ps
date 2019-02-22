#include <cstdio>

// d[n] = 주어진 수 1, 2, 3으로 n을 만들 수 있는 경우의 수
// d[n] = d[n - 1] + d[n - 2] + d[n - 3]
// d[0] = 0, d[1] = 1, d[2] = 2, d[3] = 3

int main() {
	int t, n, d[12]; scanf("%d", &t);
	d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 4; i < 12; i++) d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}
	return 0;
}