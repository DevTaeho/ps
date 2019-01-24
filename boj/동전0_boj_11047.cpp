문제 URL ___ https://www.acmicpc.net/problem/11047

#include <iostream>

using namespace std;

int N, K;

int coin[11];

void input() {
	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}
}

int getNumCoin() {
	int coin_cnt = 0;
	for (int i = N; i >= 1; i--) {
		if (coin[i] <= K) {
			coin_cnt += K / coin[i];
			K %= coin[i];
		}
	}

	return coin_cnt;
}

int main() {
	cin >> N >> K;
	input();
	cout << getNumCoin() << '\n';

	return 0;
}
