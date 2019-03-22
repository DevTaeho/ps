// 대체 왜 이렇게 짰는지 모르겠다.

#include <cstdio>
#include <queue>

using namespace std;

int map[50][50];
				 // 상, 하, 좌, 우
const int dr[4] = { -1, +1, +0, +0 };
const int dc[4] = { +0, +0, -1, +1 };

int find_next_loc(int dr, int dc) {
	// 상 1, 하 2, 좌 3, 우 4
	if (dr == -1 && dc == 0) {
		return 1;
	}
	else if (dr == 1 && dc == 0) {
		return 2;
	}
	else if (dr == 0 && dc == -1) {
		return 3;
	}
	else {
		return 4;
	}
}

bool check_valid(int nr, int nc, int code, int next_loc) {
	// code 는 현재 code
	// next_loc은 nr, nc의 상 하 좌 우 중 하나를 나타냄
	bool is_vaild = false;
	switch (code)
	{
	case 1: 
		if (next_loc == 1) {
			if (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 5 || map[nr][nc] == 6) return 1;
		}
		else if (next_loc == 2) {
			if (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 4 || map[nr][nc] == 7) return 1;
		}
		else if (next_loc == 3) {
			if (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 4 || map[nr][nc] == 5) return 1;
		}
		else if (next_loc == 4) {
			if (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 6 || map[nr][nc] == 7) return 1;
		}
		break;

	case 2: 
		if (next_loc == 1) {
			if (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 5 || map[nr][nc] == 6) return 1;
		}
		else if (next_loc == 2) {
			if (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 4 || map[nr][nc] == 7) return 1;
		}
		else if (next_loc == 3) {
			return 0;
		}
		else if (next_loc == 4) {
			return 0;
		}
		break;

	case 3: 
		if (next_loc == 1) {
			return 0;
		}
		else if (next_loc == 2) {
			return 0;
		}
		else if (next_loc == 3) {
			if (map[nr][nc] == 1 || map[nr][nc] == 4 || map[nr][nc] == 5 || map[nr][nc] == 3) return 1;
		}
		else if (next_loc == 4) {
			if (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 7 || map[nr][nc] == 6) return 1; 
		}
		break;

	case 4:
		if (next_loc == 1) {
			if (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 5 || map[nr][nc] == 6) return 1;
		}
		else if (next_loc == 2) {
			return 0;
		}
		else if (next_loc == 3) {
			return 0;
		}
		else if (next_loc == 4) {
			if (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 7 || map[nr][nc] == 6) return 1; 
		}
		break;

	case 5:
		if (next_loc == 1) {
			return 0;
		}
		else if (next_loc == 2) {
			if (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 7 || map[nr][nc] == 4) return 1;
		}
		else if (next_loc == 3) {
			return 0;
		}
		else if (next_loc == 4) {
			if (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 7 || map[nr][nc] == 6) return 1;
		}
		break;

	case 6:
		if (next_loc == 1) {
			return 0;
		}
		else if (next_loc == 2) {
			if (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 7 || map[nr][nc] == 4) return 1;
		}
		else if (next_loc == 3) {
			if (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 5 || map[nr][nc] == 4) return 1;
		}
		else if (next_loc == 4) {
			return 0; 
		}
		break;

	case 7:
		if (next_loc == 1) {
			if (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 5 || map[nr][nc] == 6) return 1;
		}
		else if (next_loc == 2) {
			return 0;
		}
		else if (next_loc == 3) {
			if (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 5 || map[nr][nc] == 4) return 1;
		}
		else if (next_loc == 4) {
			return 0; 
		}
		break;
	default:
		break;
	}

	return is_vaild;
}

vector<pair<int, int>> get_dir_weight(int code) {
	vector <pair<int, int>> res;

	switch (code)
	{
	case 1:
		for (int i = 0; i < 4; i++) res.push_back(make_pair(dr[i], dc[i]));
		break;
	case 2: 
		res.push_back(make_pair(dr[0], dc[0]));
		res.push_back(make_pair(dr[1], dc[1]));
		break;
	case 3:
		res.push_back(make_pair(dr[2], dc[2]));
		res.push_back(make_pair(dr[3], dc[3]));
		break;
	case 4:
		res.push_back(make_pair(dr[0], dc[0]));
		res.push_back(make_pair(dr[3], dc[3]));
		break;
	case 5:
		res.push_back(make_pair(dr[1], dc[1]));
		res.push_back(make_pair(dr[3], dc[3]));
		break;
	case 6:
		res.push_back(make_pair(dr[1], dc[1]));
		res.push_back(make_pair(dr[2], dc[2]));
		break;
	case 7:
		res.push_back(make_pair(dr[0], dc[0]));
		res.push_back(make_pair(dr[2], dc[2]));
		break;
	default:
		break;
	}

	return res;
}

int main() {
	int t; scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++) {
		int N, M, R, C, L;
		int ans = 0;
		bool visited[50][50] = { 0, };
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		L--;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);

		queue<pair<int, int>> q; q.push(make_pair(R, C));
		visited[R][C] = 1;

		while (L--) {
			int sz = q.size();
			while (sz--) {
				int cur_r = q.front().first;
				int cur_c = q.front().second; q.pop();
				vector<pair<int, int>> dir_weight = get_dir_weight(map[cur_r][cur_c]);

				for (int k = 0; k < dir_weight.size(); k++) {
					int next_loc = find_next_loc(dir_weight[k].first, dir_weight[k].second);
					int nr = cur_r + dir_weight[k].first;
					int nc = cur_c + dir_weight[k].second;
					if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
					if (visited[nr][nc]) continue;
					if (check_valid(nr, nc, map[cur_r][cur_c], next_loc)) {
						visited[nr][nc] = 1;
						q.push(make_pair(nr, nc));
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) if (visited[i][j]) ans++;

		printf("#%d %d\n", tc, ans);
	}

	return 0;
}
