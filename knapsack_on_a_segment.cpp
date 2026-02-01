#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, s; cin >> n >> s;

    vector<int> w(n+1), c(n+1);

    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    vector<int> px(n+1);
    partial_sum(c.begin()+1, c.end(), px.begin()+1);

    int l = 1, cur = 0, ans = 0;

    for(int r = 1; r <= n; r++) {
        cur += w[r];
        while(cur > s) cur -= w[l++];
        ans = max(ans, px[r]-px[l-1]);
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