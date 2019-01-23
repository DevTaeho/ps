#include <iostream>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;

// 빈 공간을 움직인다고 생각
// 이미 똑같은 배열의 퍼즐이 나왔다면 => 다음 연산을 수행할 필요가 없음
// 3x3 배열을 하나의 숫자로 생각 => (1, 2, 3), (4, 5, 6), (7, 8, 0) => 123456780

const int ANSWER = 123456780;
const int mv[4] = { -3, -1, +1, +3 };

bool cannotmove[9][4];

set<int> visit;

int find_zero_pos(int num) {
	int f = 100000000;
	int cnt = 0;
	while (1) {
		if ((num / f) % 10 == 0) return cnt;
		cnt++;
		f /= 10;
	}
}

int calc(int val, int zp, int nzp) {
	// val 의 zp 자리의 수와 nzp 자리의 수를 바꿈

	char temp[10];

	sprintf(temp, "%09d", val);
	char t;
	t = temp[zp];
	temp[zp] = temp[nzp];
	temp[nzp] = t;

	int res;
	res = (int)atoi(temp);
	return res;
}

int bfs(int start) {
	queue<int> q; q.push(start);
	visit.insert(start);

	bool flag = false;
	int step = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int idx = i * 3 + j;
			if (i == 0) cannotmove[idx][0] = true;
			else if (i == 2) cannotmove[idx][3] = true;
			if (j == 0) cannotmove[idx][1] = true;
			else if (j == 2) cannotmove[idx][2] = true;
		}
	}

	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int cur = q.front();
			q.pop();

			if (cur == ANSWER) {
				flag = true;
				break;
			}

			// 0의 위치를 찾음
			int zp = find_zero_pos(cur);
			for (int i = 0; i < 4; i++) {
				// 갈 수 없는 곳일 때
				if (cannotmove[zp][i]) continue;

				// 교환할 위치
				int nzp = zp + mv[i];
				// 현재 배열의 np 번째와 nzp 번째 숫자를 바꾼 next 값을 구함
				int next = calc(cur, zp, nzp);
				set<int>::iterator FindIter = visit.find(next);
				if (FindIter != visit.end()) continue;
				visit.insert(next);
				q.push(next);
			}
		}
		if (flag) break;
		step++;
	}

	if (flag) return step;
	return -1;
}

int main() {
	int f = 100000000;
	int start = 0;
	for (int i = 0; i < 9; i++) {
		int t;
		cin >> t;
		start += t * f;
		f /= 10;
	}

	cout << bfs(start) << '\n';

	system("pause");

	return 0;
}
