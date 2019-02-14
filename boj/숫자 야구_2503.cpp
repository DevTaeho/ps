#include <cstdio>
#include <stdlib.h>

int N, contents = 3;
int** RULE;

bool valid(int n) {
	bool flag = true;
	int a[3] = { n / 100 , n / 10 % 10 , n % 10 };

	if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2] || a[1] == 0 || a[2] == 0) return false;

	for (int i = 0; i < N; i++) {
		int su = RULE[i][0], s = RULE[i][1], b = RULE[i][2];
		int sus[3] = { su / 100 , su / 10 % 10, su % 10 };
		int cnt_s = 0, cnt_b = 0;
		
		if (n == su && s != 3) return false;
		else if (n == su && s == 3) return false;
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j && a[i] == sus[j]) cnt_s++;
				else if (i != j && a[i] == sus[j]) cnt_b++;
			}
		}

		if (cnt_s != s || cnt_b != b) {
			return false;
		}
	}

	return flag;
}

int main() {
	scanf("%d", &N);

	RULE = (int **)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		RULE[i] = (int *)malloc(contents * sizeof(int));
	}

	for (int i = 0; i < N; i++) {
		int su, s, b;
		scanf("%d %d %d", &su, &s, &b);
		RULE[i][0] = su; RULE[i][1] = s; RULE[i][2] = b;
	}
	
	int cnt = 0;
	for (int i = 123; i <= 987; i++) {
		if (valid(i)) cnt++;
	}

	printf("%d", cnt);

	return 0;
}
