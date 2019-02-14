#include <cstdio>
int N;
int main() {
	long long res = 0;
	int k;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &k);
			res += k;
		}
	printf("%ld", res);
	return 0;
}
