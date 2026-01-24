#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> divs;

    for(int i = 1; i*i <= n; i++) {
        if(n%i != 0) continue;
        divs.push_back(i);
        if(n/i != i) divs.push_back(n/i);
    }

    vector<int> px(n+1);
    partial_sum(all(a), px.begin()+1);

    int ans = 0;

    for(int d: divs) {
        int mn = INF, mx = -INF;
        for(int j = d; j <= n; j += d) {
            mn = min(mn, px[j]-px[j-d]);
            mx = max(mx, px[j]-px[j-d]);
        }
        ans = max(ans, mx-mn);
    }

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