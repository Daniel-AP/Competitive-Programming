#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct VectorMultiSetHasher {
	static constexpr int ms[] = {1'000'000'007, 1'000'000'403};

	size_t operator()(vector<int> const& v) const {
		int h[2] = {0, 0};

		for (int k = 0; k < 2; k++) {
			for (int x : v) {
				x %= ms[k]-1;
				if (x < 0) x += ms[k]-1;
				x++;

				int y = x;

				y = (y * 1'000'003 + 97) % ms[k];
				y = (y * y + 7 * y + 1009) % ms[k];

				h[k] += y;
				h[k] %= ms[k];
			}
		}

		return (h[0] << 32) | h[1];
	}
};

void solve() {

    int n, m; cin >> n >> m;
    int ans = 0;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, int> cnt;
    VectorMultiSetHasher hasher;

    for(int i = 1; i <= n; i++) {
        int k = hasher(adj[i]);
        cnt[k]++;
    }
    for(auto& [k, v]: cnt) ans += v*(v-1)/2;

    for(int i = 1; i <= n; i++) adj[i].push_back(i);

    cnt.clear();

    for(int i = 1; i <= n; i++) {
        int k = hasher(adj[i]);
        cnt[k]++;
    }
    for(auto& [k, v]: cnt) ans += v*(v-1)/2;

    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}