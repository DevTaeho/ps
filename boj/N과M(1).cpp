next_permutaion을 이용해 조합을 구했다..

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void comb_print(vector<char> &s, int n, int r) {
	vector<string> out;
	vector<int> ind;
	for (int i = 0; i < r; i++) {
		ind.push_back(1);
	}

	for (int i = 0; i < n - r; i++) {
		ind.push_back(0);
	}

	sort(ind.begin(), ind.end());

	do {

		string temp = "";

		for (int i = 0; i < n; i++) {
			int k = 0;
			if (ind[i] == 1) {
				if (k == r - 1) {
					temp += s[i];
				}
				else {
					temp += s[i];
					temp += " ";
				}
				k++;
			}
		}

		out.push_back(temp);

	} while (next_permutation(ind.begin(), ind.end()));

	sort(out.begin(), out.end());

	for (unsigned int i = 0; i < out.size(); i++) {
		cout << out[i] << '\n';
	}

}

int main() {
	int N, M;
	cin >> N >> M;

	vector<char> su;
	for (int i = 1; i <= N; i++) {
		su.push_back(i + 48);
	}
	
	comb_print(su, N, M);

	return 0;
}
