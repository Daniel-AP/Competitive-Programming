#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

typedef struct uf {
	int *ids, *sizes;

	uf(int n) {
		ids = new int[n];
		sizes = new int[n];

		for(int i = 0; i < n; i++) {
			ids[i] = i;
			sizes[i] = 1;
		}
	}

	int f(int i) {
		int p = i;
		while(ids[p] != p)
			p = ids[p];

		while(ids[i] != i) {
			int pp = ids[i];
			ids[i] = p;
			i = pp;
		}

		return p;
	}

	void u(int i, int j) {
		int p1 = f(i), p2 = f(j);
		if(p1 == p2) return;

		int nS = sizes[p1]+sizes[p2];

		if(sizes[p1] < sizes[p2]) {
			ids[p1] = p2;
		} else {
			ids[p2] = p1;
		}

		sizes[p1] = sizes[p2] = nS;
	}
} UnionFind;

void solve() {

    int n, m; cin >> n >> m;

    
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}