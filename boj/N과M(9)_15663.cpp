문제 URL ___ https://www.acmicpc.net/problem/15663

기존 N과 M 문제에서 입력에 중복되는 원소가 있는 경우의 문제다

set을 이용해서 중복되는 조합을 출력시 제외시켰다

중복인지 아닌지는 26~29 라인과 같이 각 자리수로 생각하고 모두 더한 뒤

set에 insert 했다

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N, M, p[8], a[8];
bool used[8];
set<int> check;

void solve(int depth) {
	if (depth == M) {
		int sum = 0;
		int k = 1;
		
		for (int i = 0; i < M; i++) {
			sum += p[i] * k;
			k *= 10;
		}
		set<int>::iterator FindIter = check.find(sum);
		if (FindIter == check.end()) {
			for (int i = 0; i < M; i++) {
				cout << p[i] << ' ';
			}
			cout << '\n';
		}

		check.insert(sum);
		
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
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a, a + N);

	solve(0);

	return 0;
}
