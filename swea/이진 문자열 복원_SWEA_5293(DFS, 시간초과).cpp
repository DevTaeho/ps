시간 초과지만 
ios::sync_with_stdio(false);
cin.tie(NULL);

두 문장을 넣어주면 속도가 엄청 증가하는 마법..


#include <iostream>
#include <string>

using namespace std;

string result;

void solve(string res, int a, int b, int c, int d);

int main() {
	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++) {
		int A, B, C, D;
		cin >> A >> B >> C >> D;

		result = "\0";
		solve("0", A, B, C, D);
		solve("1", A, B, C, D);
		if (result == "\0") result = "impossible";

		cout << "#" << tc << ' ' << result << '\n';
	}

	return 0;
}

void solve(string res, int a, int b, int c, int d) {
	if (result != "\0") return;
	if (b - c > 1 || c - b > 1) return;
	if (a < 0 || b < 0 || c < 0 || d < 0) return;
	if (a == 0 && b == 0 && c == 0 && d == 0) {
		result = res;
		return;
	}
	
	if (res.back() == '0') {
		solve(res + "1", a, b - 1, c, d);
		solve(res + "0", a - 1, b, c, d);
	}
	else if (res.back() == '1') {
		solve(res + "1", a, b, c, d - 1);
		solve(res + "0", a, b, c - 1, d);
	}
}
