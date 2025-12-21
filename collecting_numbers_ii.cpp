#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    vector<int> ind(n);

    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j) { return x[i] < x[j]; });

    int ans = 1;

    for(int i = 1; i < n; i++) {
        if(ind[i-1] > ind[i]) ans++;
    }

    while(m--) {

        int a, b; cin >> a >> b;
        a--, b--;

        if(x[a] > 1) ans -= ind[x[a]-2]>ind[x[a]-1];
        if(x[b] > 1) ans -= ind[x[b]-2]>ind[x[b]-1];
        if(x[a] < n && x[a]-1 != x[b]-2) ans -= ind[x[a]-1]>ind[x[a]];
        if(x[b] < n && x[b]-1 != x[a]-2) ans -= ind[x[b]-1]>ind[x[b]];

        swap(x[a], x[b]);
        swap(ind[x[a]-1], ind[x[b]-1]);

        if(x[a] > 1) ans += ind[x[a]-2]>ind[x[a]-1];
        if(x[b] > 1) ans += ind[x[b]-2]>ind[x[b]-1];
        if(x[a] < n && x[a]-1 != x[b]-2) ans += ind[x[a]-1]>ind[x[a]];
        if(x[b] < n && x[b]-1 != x[a]-2) ans += ind[x[b]-1]>ind[x[b]];

        cout << ans << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}