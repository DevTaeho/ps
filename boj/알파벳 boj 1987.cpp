문제 URL ___ https://www.acmicpc.net/problem/1987

backtracking을 사용하여 해결했다

#include <iostream>

using namespace std;

int R, C;
int m = 1;
char map[21][21];
bool alpha_used[26];
bool visited[21][21];

void backtrack(int depth, char cur, int cur_row, int cur_col) {
	if (alpha_used[cur - 'A']) return;
	if (depth > m) m = depth;

	visited[cur_row][cur_col] = true;
	alpha_used[cur - 'A'] = true;

	// 동쪽
	int row_east = cur_row; int col_east = cur_col + 1;
	// 동쪽 알파벳이 사용되지 않았는지 체크
	if (!alpha_used[map[row_east][col_east] - 'A'] && !visited[row_east][col_east]) {
		if (1 <= row_east && row_east <= R && 1 <= col_east && col_east <= C) {
			backtrack(depth + 1, map[row_east][col_east], row_east, col_east);
		}
	}

	// 서쪽
	int row_west = cur_row; int col_west = cur_col - 1;
	if (!alpha_used[map[row_west][col_west] - 'A'] && !visited[row_west][col_west]) {
		if (1 <= row_west && row_west <= R && 1 <= col_west && col_west <= C) {
			backtrack(depth + 1, map[row_west][col_west], row_west, col_west);
		}
	}

	// 남쪽
	int row_south = cur_row + 1; int col_south = cur_col;
	if (!alpha_used[map[row_south][col_south] - 'A'] && !visited[row_south][col_south]) {
		if (1 <= row_south && row_south <= R && 1 <= col_south && col_south <= C) {
			backtrack(depth + 1, map[row_south][col_south], row_south, col_south);
		}
	}

	// 북쪽
	int row_north = cur_row - 1; int col_north = cur_col;
	if (!alpha_used[map[row_north][col_north] - 'A'] && !visited[row_north][col_north]) {
		if (1 <= row_north && row_north <= R && 1 <= col_north && col_north <= C) {
			backtrack(depth + 1, map[row_north][col_north], row_north, col_north);
		}
	}

	visited[cur_row][cur_col] = false;
	alpha_used[cur - 'A'] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}

	backtrack(1, map[1][1], 1, 1);

	cout << m << '\n';

	return 0;
}
