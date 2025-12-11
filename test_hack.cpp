#include <bits/stdc++.h>
#define int long long

using namespace std;

map<int, vector<int>> children;

void dfs(int v) {

	cout << v << ' ';

	for(int x: children[v]) {
		dfs(x);
	}

}

void bfs() {

	queue<int> q;
	q.push(0);

	while(!q.empty()) {
		int k = q.front(); q.pop();
		cout << k << ' ';
		for(int x: children[k]) q.push(x);
	}

}

signed main() {

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	for(int t = 0; t < n; t++) {

		int v, h; cin >> v >> h;
		children[v].assign(h, 0);

		for(int i = 0; i < h; i++) cin >> children[v][i];

	}

	bfs();
	cout << '\n';
	dfs(0);

	return 0;
}