문제 URL ___ https://www.acmicpc.net/problem/15651

N과M(2) 에서 이미 지났던 노드를 지나지 않는다는 의미에서 활용되었던 visited 배열을 사용하지 않았다
따라서 이는 자신을 사용해도 다시 자신을 사용할 수 있다는 의미가 된다

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
		p[depth] = i+1;
		solve(n, r, depth + 1);
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	solve(N, M, 0);

	return 0;
}
