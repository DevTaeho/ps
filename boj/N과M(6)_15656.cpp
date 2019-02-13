문제 링크 ___ https://www.acmicpc.net/problem/15656

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, a[8], p[8];

void solve(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << p[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		p[depth] = a[i];
		solve(depth + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a, a + N);

	solve(0);

	return 0;
}
