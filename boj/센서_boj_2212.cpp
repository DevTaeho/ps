문제 URL ___ https://www.acmicpc.net/problem/2212

만약 센서가 1 - 4 - 6 - 7 - 12 에 위치해 있고
집중국을 2개 놓을 수 있다고 하자

각 센서 사이의 거리를 보면 
(1 - 4 - 6 - 7 - 12)
   3 - 2 - 1 - 5 가 된다

여기서 집중국 2개를 놓을 수 있는 경우는
 1 영역을 커버하는 집중국과 4 - 6 - 7 - 12를 커버하는 집중국 => 최소 영역 8 ( 11 - 3 )
 1 - 4 영역을 커버하는 집중국과, 6 - 7 - 12를 커버하는 집중국 => 최소 영역 9 ( 11 - 9 )
 1 - 4 - 6 영역을 커버하는 집중국과, 7 - 12를 커버하는 집중국 => 최소 영역 10 ( 11 - 1)
 1 - 4 - 6 - 7 영역을 커버하는 집중국과, 12를 커버하는 집중국 => 최소 영역 7 ( 11 - 5 )

가 있다
보다시피 센서와 센서 사이의 거리가 가장 긴 경우에 이 두 센서를 기준으로 집중국을 나누면 집중국이 커버하는 영역이 최소가 되게끔 할 수 있다.
결국, 
1. 센서들의 위치를 입력 받고
2. 센서 사이의 거리를 저장하고
3. 센서 사이의 거리를 저장한 자료구조를 정렬한 후
4. 놓을 수 있는 최대 집중국 수 - 1 ( = K - 1 ) 개 만큼 뒤에서 자료를 제거한 뒤
5. 남은 센서들 사이의 거리 값을 모두 더하면 정답이 된다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int sensorLoc[10001];
vector<int> area;

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> sensorLoc[i];
	}

	sort(sensorLoc, sensorLoc + N);

	for (int i = 0; i < N - 1; i++) {
		if (sensorLoc[i + 1] - sensorLoc[i] > 0) {
			area.push_back(sensorLoc[i + 1] - sensorLoc[i]);
		}
	}

	sort(area.begin(), area.end());

	int c = K - 1;
	while (c--) {
		if (area.empty()) break;
		area.pop_back();
	}

	int res = 0;
	for (int i = 0; i < area.size(); i++) {
		res += area[i];
	}

	cout << res << '\n';

	system("pause");

	return 0;
}
