#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> p(n+1);
    vector<vector<int>> children(n+1);
    vector<pair<int, int>> smx(n+1);

    p[1] = 0;
    for(int i = 2; i <= n; i++) cin >> p[i];

    for(int i = 2; i <= n; i++) {
        children[p[i]].push_back(i);
    }

    auto dfsmx = [&](auto&& self, int u) -> int {
        
        int mx1 = -INF, mx2 = -INF;

        for(int x: children[u]) {
            int h = self(self, x);
            if(h > mx1) mx2 = mx1, mx1 = h;
            else if(h > mx2) mx2 = h;
        }

        smx[u] = {mx1, mx2};

        return max(mx1+1, 0LL);

    };

    dfsmx(dfsmx, 1);

    int ans = n;

    auto dfs = [&](auto&& self, int u) -> void {
        if(smx[u].second != -INF) ans += smx[u].second+1;
        for(int x: children[u]) self(self, x);
    };

    dfs(dfs, 1);

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}