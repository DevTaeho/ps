문제 URL ___ https://www.acmicpc.net/problem/15654

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, a[8], p[8];
bool used[8];

void solve(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << p[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			used[i] = true;
			p[depth] = a[i];
			solve(depth + 1);
			used[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> a[i];

	sort(a, a + N);
	solve(0);

	return 0;
}
