문제 URL ___ https://www.acmicpc.net/problem/1931

Greedy 알고리즘을 이용해서 푼다
회의가 끝나는 시간을 기준으로 정렬하고
정렬했을 때 끝나는 시간이 같은 회의가 2개 이상 존재한다면 회의 시작 기준으로 정렬한다

시작시간 끝나는시간 을 vector에 pair<end, start> 형태로 넣었다
이 vector를 정렬하면 위의 설명과 같이 정렬된다

결국 끝나는 시간이 제일 빠르고 그 중 시작 시간이 제일 빠른 녀석 하나를 선택(v[0~N-1])하고 
이전 요소의 끝나는 시간(prev)와 비교한다
비교했을 때 prev 와 같거나 큰 시작 시간을 가진 벡터의 다음 요소를 선택한다. 그리고 ans를 1증가 시킨다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ e, s });
	}

	sort(v.begin(), v.end());

	int ans = 0;
	int prev = -1;
	for (int i = 0; i < N; i++) {
		if (v[i].second >= prev) {
			ans++;
			prev = v[i].first;
		}
	}

	cout << ans << '\n';

	system("pause");

	return 0;
}
