#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end());

    vector<int> px(m+1);
    partial_sum(b.begin(), b.end(), px.begin()+1);

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int j = upper_bound(b.begin(), b.end(), a[i])-b.begin();
        ans += a[i]*j-px[j];
        ans %= MOD;
        ans += (px[m]-px[j])-a[i]*(m-j);
        ans %= MOD;
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