#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> x(n);

    for(int i = 0; i < n; i++) {
        int m; cin >> m;
        x[i] = { m, i };
    }

    sort(x.begin(), x.end());

    int ans = 1;

    for(int i = 1; i < n; i++) {
        if(x[i-1].second > x[i].second) ans++;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}