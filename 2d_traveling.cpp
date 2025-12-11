#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, a, b; cin >> n >> k >> a >> b;
    a--, b--;

    vector<pair<int, int>> xy(n);
    for(auto& p: xy) cin >> p.first >> p.second;

    int d1 = INF, d2 = INF;

    for(int i = 0; i < k; i++) {
        d1 = min(d1, abs(xy[i].first-xy[a].first)+abs(xy[i].second-xy[a].second));
        d2 = min(d2, abs(xy[i].first-xy[b].first)+abs(xy[i].second-xy[b].second));
    }

    if(a < k && b < k) cout << 0;
    else if(a < k) cout << d2;
    else if(b < k) cout << d1;
    else cout << min(d1+d2, abs(xy[b].first-xy[a].first)+abs(xy[b].second-xy[a].second));
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