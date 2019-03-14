#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define ll long long

using namespace std;

int N, K, rot;
char d[4][10];
vector<string> v;
deque<char> in;

ll conv(string s) {
	ll res = 0;
	ll g = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		char t = s[i];
		int x;
		if ('0' <= t && t <= '9') x = t - '0';
		else {
			switch (t)
			{
			case 'A': x = 10; break;
			case 'B' : x = 11; break;
			case 'C' : x = 12; break;
			case 'D' : x = 13; break;
			case 'E' : x = 14; break;
			case 'F' : x = 15; break;
			default:
				break;
			}
		}
		res += g * x;
		g *= 16;
	}

	return res;
}

void rot_insert(int r) {
	if (r == 0) {
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < rot; k++) {
				d[i][k] = in[i*rot + k];
			}
		}

		for (int i = 0; i < 4; i++) {
			v.push_back(d[i]);
		}
	}
	else {
		char b = in.back(); in.pop_back();
		in.push_front(b);

		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < rot; k++) {
				d[i][k] = in[i*rot + k];
			}
		}

		for (int i = 0; i < 4; i++) {
			v.push_back(d[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testc;
	cin >> testc;

	for (int tc = 1; tc <= testc; tc++) {
		v.clear(); in.clear();
		cin >> N >> K;
		in.resize(N);

		rot = N / 4;

		for (int i = 0; i < N; i++) {
			char t; cin >> in[i];
		}

		for (int i = 0; i < rot; i++) {
			rot_insert(i);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		reverse(v.begin(), v.end());

		cout << '#' << tc << ' ' << conv(v[K-1]) << '\n';
	}
	return 0;
}
