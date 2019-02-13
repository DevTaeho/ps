문제 URL ___ https://www.acmicpc.net/problem/15652

기존 N과 M 문제에서 backtrack 조건을 아래와 같이 건다

#include <iostream>

using namespace std;

int p[8], N, M;

void solve(int pos, int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) cout << p[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
    // 현재 값보다 다음 노드의 값이 크거나 같을 경우 진행
		if (pos <= i) {
			p[depth] = i;
			solve(i, depth + 1);
		}
	}
}

int main() {
	cin >> N >> M;

	solve(1, 0);

	return 0;
}
