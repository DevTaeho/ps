#include <iostream>
#include <string>

using namespace std;

string dp[21][21][21][21][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;

	init();
	
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++) {
		int A, B, C, D;
		string res;
		cin >> A >> B >> C >> D;

		
		if (!dp[A][B][C][D][0].empty()) res = dp[A][B][C][D][0];
		else if (!dp[A][B][C][D][1].empty()) res = dp[A][B][C][D][1];
		else res = "impossible";
		cout << "#" << tc << ' ' << res << '\n';
	}

	system("pause");

	return 0;
}

void init() {
	dp[1][0][0][0][0] = "00";
	dp[0][1][0][0][1] = "01";
	dp[0][0][1][0][0] = "10";
	dp[0][0][0][1][1] = "11";

	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int k = 0; k <= 20; k++) {
				for (int m = 0; m <= 20; m++) {
					if (i > 0 && !dp[i - 1][j][k][m][0].empty()) {
						dp[i][j][k][m][0] = dp[i - 1][j][k][m][0] + "0";
					}
					if (j > 0 && !dp[i][j - 1][k][m][0].empty()) {
						dp[i][j][k][m][1] = dp[i][j - 1][k][m][0] + "1";
					}
					if (k > 0 && !dp[i][j][k - 1][m][1].empty()) {
						dp[i][j][k][m][0] = dp[i][j][k - 1][m][1] + "0";
					}
					if (m > 0 && !dp[i][j][k][m - 1][1].empty()) {
						dp[i][j][k][m][1] = dp[i][j][k][m - 1][1] + "1";
					}
				}
			}
		}
	}
}
