#include <cstdio>
#define _min(a, b) a<b ? a:b

int main() {
	int n, k, p[100], res = 100000, d[10001];
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= k; i++) d[i] = res;
	d[0] = 0;
	for (int i = 0; i < n; i++) scanf("%d", &p[i]);
	for (int i = 0; i < n; i++)
		for (int j = p[i]; j <= k; j++) d[j] = _min(d[j], d[j - p[i]] + 1);
	d[k] != res ? res = d[k] : res = -1;
	printf("%d", res);
	return 0;
}
