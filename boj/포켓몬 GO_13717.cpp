#include <iostream>
#include <string>

using namespace std;
int k[70], m[70], evol[70];
string mon[70];
int main() {
	int N; 
	cin >> N;

	int total_ev = 0;
	for (int i = 0; i < N; i++) {
		int ev = 0;
		cin >> mon[i];
		cin >> k[i] >> m[i];
		while (m[i] - k[i] >= 0) {
			m[i] -= k[i];
			m[i] += 2;
			ev++;
			total_ev++;
		}
		evol[i] = ev;
	}

	int max = -111;
	for (int i = 0; i < N; i++) if (max < evol[i]) max = evol[i];
	for (int i = 0; i < N; i++) {
		if (evol[i] == max) {
			cout << total_ev << '\n' << mon[i];
			break;
		}
	}
	return 0;
}