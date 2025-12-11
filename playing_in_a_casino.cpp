#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> a(m, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[j][i];
        }
    }
    
    for(int i = 0; i < m; i++) {
        sort(a[i].begin(), a[i].end());
    }

    int ans = 0;

    vector<int> prefix(n+1);

    for(int i = 0; i < m; i++) {
        partial_sum(a[i].begin(), a[i].end(), prefix.begin()+1);
        for(int j = 0; j < n; j++) {
            ans += (prefix[n]-prefix[j+1])-a[i][j]*(n-j-1);
        }
    }

    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}