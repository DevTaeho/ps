#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;

int main() {
	int n; scanf("%d", &n); a.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	if (next_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++) printf("%d ", a[i]);
	}
	else printf("-1");
}