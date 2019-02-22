#include <cstdio>

int main() {
	int E, S, M; scanf("%d %d %d", &E, &S, &M);
	int cnt = 1;
	int a = 1, b = 1, c = 1;
	while (1) {
		if (a == E && b == S && c == M) break;

		a++; b++; c++;
		a <= 15 ? a = a : a = 1;
		b <= 28 ? b = b : b = 1;
		c <= 19 ? c = c : c = 1;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}