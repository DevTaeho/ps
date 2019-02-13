#include <iostream>
#include <algorithm>

using namespace std;

int N, M, p[8], a[8];

void solve(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << p[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (depth == 0) {
			p[depth] = a[i];
			solve(depth + 1);
		}
		else {
			if (p[depth - 1] <= a[i]) {
				p[depth] = a[i];
				solve(depth + 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> a[i];

	sort(a, a + N);

	solve(0);

	return 0;
}
