문제 URL ___ https://www.acmicpc.net/problem/15649
함수의 재귀 호출을 통해 풀었다

#include <iostream>

using namespace std;

int p[8];
bool visited[8];

void solve(int n, int r, int depth) {
	if (depth == r) {
		for (int i = 0; i < depth; i++) {
			cout << p[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			p[depth] = i+1;
			solve(n, r, depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	solve(N, M, 0);
	
	return 0;
}
