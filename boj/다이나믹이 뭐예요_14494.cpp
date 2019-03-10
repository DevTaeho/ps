#include <cstdio>
#define ll long long
ll d[1001][1001], mod = 1e9 + 7;
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	d[1][1] = 1;
	d[1][2] = 1;
	d[2][1] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1)) continue;
			d[i][j] = (d[i][j - 1] + d[i - 1][j] + d[i - 1][j - 1]) % mod;
		}
	}

	printf("%lld\n", d[n][m] % mod);
	return 0;
}