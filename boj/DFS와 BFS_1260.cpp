#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, F;
vector<int> G[1001];
bool v[1001], v2[1001];

void bfs(int c) {
	queue<int> q; q.push(c);
	v2[c] = true;

	while (!q.empty()) {
		c = q.front(); q.pop();
		printf("%d ", c);
		for (int i = 0; i < G[c].size(); i++) 
			if (!v2[G[c][i]]) {
				v2[G[c][i]] = true;
				q.push(G[c][i]);
			}
	}
}

void dfs(int c) {
	v[c] = true;
	printf("%d ", c);
	for (int i = 0; i < G[c].size(); i++) {
		if (!v[G[c][i]]) dfs(G[c][i]);
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &F);
	while(M--) {
		int U, V; scanf("%d %d", &U, &V);
		G[U].push_back(V); G[V].push_back(U);
	}
	for (int i = 0; i < N; i++) sort(G[i].begin(), G[i].end());
	dfs(F);
	printf("\n");
	bfs(F);
	return 0;
}
