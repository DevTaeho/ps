문제 URL ___ https://www.acmicpc.net/problem/1525



#include <iostream>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;

// 빈 공간을 움직인다고 생각
// 이미 똑같은 배열의 퍼즐 배열이 나왔다면 => 다음 연산을 수행할 필요가 없음
// 3x3 배열을 하나의 숫자로 생각 => (1, 2, 3), (4, 5, 6), (7, 8, 0) => 123456780

// 최종적으로 나타나야 하는 퍼즐의 모양이다
// 123456780
// = 1 2 3
//   4 5 6
//   7 8 0
const int ANSWER = 123456780;

// 빈 공간의 움직이는 방향과 거리라고 생각하면 된다.
// 1 2 3
// 4 5 7
// 6   8 왼쪽같이 퍼즐이 주어졌을 때 빈 공간은 +1, -3, -1로 이동할 수 있으며 +3으로 이동할 순 없다

const int mv[4] = { -3, -1, +1, +3 };

// 빈 공간의 위치(행)에 대해 이동할 수 없는 좌표를 나타내기 위한 배열
// mv[4] 의 이동 경로에 영향을 받는다
bool cannotmove[9][4];

// 3x3 배열의 방문 여부를 확인하기 위한 set 변수
set<int> visit;

// num을 입력받아 num에서 각 자리의 수를 확인 했을 때 자리 수가 0일 때 자리 수를 리턴한다.
int find_zero_pos(int num) {
	int f = 100000000;
	int cnt = 0;
	while (1) {
		if ((num / f) % 10 == 0) return cnt;
		cnt++;
		f /= 10;
	}
}

// val 값에서 zp 자리에 있는 숫자와 nzp 자리에 있는 숫자를 바꾼 후 리턴한다
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

// bfs를 사용해서 조합 가능한 모든 퍼즐을 탐색한다
int bfs(int start) {
	queue<int> q; q.push(start);
	visit.insert(start);

	bool flag = false;
	int step = 0;

	// 검사 시작 인덱스인 idx에서 퍼즐 구조 상 갈 수 없는 곳을 true로 바꾼다
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int idx = i * 3 + j;
			if (i == 0) cannotmove[idx][0] = true;
			else if (i == 2) cannotmove[idx][3] = true;
			if (j == 0) cannotmove[idx][1] = true;
			else if (j == 2) cannotmove[idx][2] = true;
		}
	}

	// 큐로 가능한 방향을 모두 탐색
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

	// 답 출력. ANSWER가 되는 원소를 찾지 못했다면 -1을 리턴 받았을거고, ANSWER와 일치하는 퍼즐을 찾았다면 step 수를 리턴 받았겠지!?
	cout << bfs(start) << '\n';

	return 0;
}
