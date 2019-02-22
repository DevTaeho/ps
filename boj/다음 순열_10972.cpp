#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int a[10001];

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	int idx = n - 1;
	while (a[idx - 1] > a[idx]) idx--;

	if (idx == 0) {
		printf("-1");
		return 0;
	}

	for (int i = n - 1; i >= idx; i--) {
		if (a[i] > a[idx - 1]) {
			swap(a[i], a[idx - 1]);
			break;
		}
	}

	sort(a + idx, a + n);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}