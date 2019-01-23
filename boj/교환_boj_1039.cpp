문제 URL ___ https://www.acmicpc.net/problem/1039

유사한 문제 boj_1525, boj_9019

K번 연산을 할 수 없을 경우에 대한 예외 처리가 89~92 라인에 있다. 이를 처리하지 않아서 트라이를 많이 했다.

#include <iostream>
#include <queue>

using namespace std;

int N, K, M;

const int ERR = -99999;

// val 값의 a 번째 자리와 b 번째 자리 수를 교환
int change(int val, int a, int b) {
	// val값의 a 자리 수와 b 자리 수 교환
	char *c = (char*)malloc(M * sizeof(char) + 1);
	sprintf(c, "%d", val);

	// a가 수의 첫 자리를 나타내고, 교환하려는 값이 (c[b]) '0' 일 경우 0을 리턴
	if (c[b] == '0' && a == 0) return ERR;

	char t;
	t = c[a];
	c[a] = c[b];
	c[b] = t;
	
	return (int)atoi(c);
}

// a, b 중 큰값 구하는 함수
int _max(int a, int b) { return a > b ? a : b; }

// 시작 값인 'N'을 기준으로 모든 조합에 대해 ( i = 0~M-2, j = i+1~M ) i와 j 자리의 수를 교환한 값을 큐에 넣고 다음 연산을 진행한다. 
int bfs(int n) {
	queue<int> q; q.push(n);
	int max = -1;

	for (int cnt = 0; cnt <= K; cnt++) {
		int size = q.size();

		bool visited[1000001] = { false, };

		while (size--) {
			int val = q.front();
			q.pop();

			if (cnt == K || ((K - cnt) & 1) == 0) {
				max = _max(max, val);
				if (cnt == K) continue;
			}

			for (int i = 0; i < M - 1; i++) {
				for (int j = i + 1; j < M; j++) {
					// i번째 수와 j번째 수를 교환한 값을 전부 넣기
					int next = change(val, i, j);
					if (next == ERR) continue;
					if (!visited[next]) {
						visited[next] = true;
						if (cnt == K) {
							max = _max(max, next);
						}
						q.push(next);
					}
				}
			}
		}
	}

	return max;
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d %d", &N, &K);
	int f = 10;
	int cnt = 1;
	while (1) {
		if (N / f == 0) {
			M = cnt;
			break;
		}
		f *= 10;
		cnt++;
	}

	if (M == 1 || (M == 2 && N % 10 == 0)){
		cout << "-1" << '\n';
		return 0;
	}

	cout << bfs(N) << '\n';
	system("pause");

	return 0;
}
