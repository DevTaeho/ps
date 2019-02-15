#include <cstdio>

int n, k, d[10001], p;

int main() {
	scanf("%d %d", &n, &k);
	d[0] = 1;
	while (n--) {
		scanf("%d", &p);
		for (int i = 0; i <= k; i++) if(i >= p) d[i] += d[i - p];
	}
	printf("%d", d[k]);
	return 0;
}
