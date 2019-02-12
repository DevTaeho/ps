문제 URL ___ https://www.acmicpc.net/problem/9095

---------------------------bactracking---------------------------
#include <iostream>

using namespace std;
int res = 0;

int su[3] = { 1, 2, 3 };

void solve(int sum, int ans) {
	if (sum == ans) res++;
	if (sum > ans) return;

	for (int i = 0; i < 3; i++) {
		solve(sum + su[i], ans);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x; res = 0;
		cin >> x;
		solve(0, x);

		cout << res << '\n';
	}

	return 0;
}
--------------------------------------------------------

---------------------------dp---------------------------
#include <iostream>

using namespace std;
int d[1001];

int tiling(int n);

int main() {
	ios::sync_with_stdio(false);

	int time, temp;
	cin >> time;
	temp = time;
	int n[11];

	for (int i = 0; i < time; i++) {
		cin >> n[i];
	}

	for (int i = 0; i < time; i++) {
		cout << tiling(n[i]) << '\n';
	}

	return 0;
}

int tiling(int n) {

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i-2] + d[i-3]);
	}

	return d[n]; //여기서 d[n]은 n을 1,2,3 의 조합으로 나타내는 방법의 수
}
--------------------------------------------------------
