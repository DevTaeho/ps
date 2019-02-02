각 균형점을 이진 탐색을 활용해 구했다
지정한 지점을 기준으로 leftPower와 rightPower를 구하고
leftPower가 더 크다면 [mid:right] 구간에서 다시 인력를 구하고
rightPower가 크다면 [left:mid] 구간에서 다시 인력을 구한다
이를 100회 정도 반복한다

그럼 얼추 답은 나오는데
오차 범위에 대한 증명은 어떻게 해야되는거지..?

#include <iostream>

using namespace std;

int N;					// 자성체 개수
double curX[11];		// 자성체들의 위치
double curW[11];		// 자성체들의 무게
double G = 1;
double W = 1;

double binary_search(double left, double right, int depth) {
	double mid = (left + right) / 2;
	if (depth == 100) return mid;
	// cur을 기준으로 좌측 인력, 우측 인력을 구한 후
	
	double leftPower = 0;
	double rightPower = 0;
	double idx;

	int i = 0;
	while (curX[i] < mid) {
		leftPower += (G * curW[i] * W) / ((mid - curX[i]) * (mid - curX[i]));
		i++;
	}

	while (curX[i] > mid && i <= N) {
		rightPower += (G * curW[i] * W) / ((mid - curX[i]) * (mid - curX[i]));
		i++;
	}

	double F = leftPower - rightPower;

	if (F == 0) {
		idx = mid;
	}
	else if(F > 0) {
		// 왼쪽 빠워가 더 큰 경우
		// 오른쪽으로 옮겨야함..
		idx = binary_search(mid, right, depth + 1);
	}
	else if (F < 0) {
		// 쪽 빠워가 더 큰 경우
		idx = binary_search(left, mid, depth + 1);
	}

	return idx;
}
int main() {
	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> curX[i];
		}
		
		for (int i = 1; i <= N; i++) {
			cin >> curW[i];
		}

		double left;
		double right;
		double ans_idx;
		printf("#%d ", tc);
		for (int i = 1; i <= N - 1; i++) {
			left = curX[i];
			right = curX[i + 1];
			ans_idx = binary_search(left, right, 0);
			printf("%.10f ", ans_idx);
		}
		printf("\n");
		
	}
	
	return 0;
}
