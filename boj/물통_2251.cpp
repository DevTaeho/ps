#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int x, y, z;
};

int A_buc, B_buc, C_buc;
bool visit[201][201];
vector<int> ans;


void bfs() {
	queue<node> q; node first; first.x = 0; first.y = 0; first.z = C_buc;
	q.push(first);

	visit[0][0] = 1;

	while (!q.empty()) {
		node cur = q.front(); q.pop();
		int cur_a = cur.x;
		int cur_b = cur.y;
		int cur_c = cur.z;

		if (cur_a == 0) ans.push_back(cur_c);

		// a->b
		if (cur_a + cur_b > B_buc) {
			int next_b = B_buc;
			int next_a = cur_a + cur_b - B_buc;
			int next_c = C_buc - next_b - next_a;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}
		else {
			int next_b = cur_a + cur_b;
			int next_a = 0;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = cur_c;
				q.push(next);
			}
		}
		// a->c
		if (cur_a + cur_c > C_buc) {
			int next_c = C_buc;
			int next_a = cur_a + cur_c - C_buc;
			int next_b = C_buc - next_a - next_c;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}
		else {
			int next_a = 0;
			int next_c = cur_a + cur_c;
			int next_b = C_buc - next_a - next_c;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}

		// b->a
		if (cur_b + cur_a > A_buc) {
			int next_a = A_buc;
			int next_b = cur_a + cur_b - A_buc;
			int next_c = C_buc - next_a - next_b;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}
		else {
			int next_a = cur_b + cur_a;
			int next_b = 0;
			int next_c = C_buc - next_a - next_b;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}

		// b->c
		if (cur_b + cur_c > C_buc) {
			int next_c = C_buc;
			int next_b = cur_c + cur_b - C_buc;
			int next_a = C_buc - next_c - next_b;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}
		else {
			int next_b = 0;
			int next_c = cur_b + cur_c;
			int next_a = C_buc - next_b - next_c;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}

		//c->a
		if (cur_c + cur_a > A_buc) {
			int next_a = A_buc;
			int next_c = cur_c + cur_a - A_buc;
			int next_b = C_buc - next_a - next_c;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}
		else {
			int next_c = 0;
			int next_a = cur_a + cur_c;
			int next_b = C_buc - next_a - next_c;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}

		//c->b
		if (cur_c + cur_b > B_buc) {
			int next_b = B_buc;
			int next_c = cur_c + cur_b - B_buc;
			int next_a = C_buc - next_b - next_c;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}
		else {
			int next_c = 0;
			int next_b = cur_b + cur_c;
			int next_a = C_buc - next_b - next_c;
			if (!visit[next_a][next_b]) {
				visit[next_a][next_b] = 1;
				node next; next.x = next_a; next.y = next_b; next.z = next_c;
				q.push(next);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &A_buc, &B_buc, &C_buc);
	bfs();
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}