#include <cstdio>
#include <vector>

bool v[1001]; 
std::vector<std::vector<int>> G(1001);

void dfs(int S) {
	v[S] = true;
	for (int i = 0; i < G[S].size(); i++) {
		if (!v[G[S][i]]) {
			dfs(G[S][i]);
		}
	}
}

int main() {
	int N, M, cnt = 0; scanf("%d %d", &N, &M);
	while (M--) {
		int U, V; scanf("%d %d", &U, &V);
		G[U].push_back(V); G[V].push_back(U);
	}
	for (int i = 1; i <= N; i++) {
		if (!v[i]) { 
			dfs(i);
			cnt++;
		}
		
	}
	printf("%d", cnt);
	return 0;
}