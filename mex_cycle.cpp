#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x, y; cin >> n >> x >> y;

    vector<vector<int>> adj(n+1);

    for(int i = 1; i <= n; i++) {
        adj[i].push_back(i == 1 ? n : i-1);
        adj[i].push_back(i == n ? 1 : i+1);
    }

    if(y != (x == 1 ? n : x-1) && y != (x == n ? 1 : x+1)) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans(n+1);

    for(int i = 1; i <= n; i++) {
        array<int, 5> cnt{};
        for(int j: adj[i]) cnt[ans[j]]++;
        int mex = 0;
        while(cnt[mex]) mex++;
        ans[i] = mex;
    }

    for(int i = 1; i <= n; i++) {
        array<int, 5> cnt{};
        for(int j: adj[i]) cnt[ans[j]]++;
        int mex = 0;
        while(cnt[mex]) mex++;
        ans[i] = mex;
    }
    
    for(int i = 1; i <= n; i++) {
        array<int, 5> cnt{};
        for(int j: adj[i]) cnt[ans[j]]++;
        int mex = 0;
        while(cnt[mex]) mex++;
        ans[i] = mex;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}