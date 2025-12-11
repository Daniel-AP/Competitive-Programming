#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x, m; cin >> n >> x >> m;

    vector<pair<int, int>> p(m);
    for(int i = 0; i < m; i++) cin >> p[i].first >> p[i].second;

    bool can = p[0].first <= x && x <= p[0].second;
    int l = p[0].first, r = p[0].second;

    vector<pair<int, int>> a;

    for(int i = 1; i < m; i++) {
        int k = min(p[i].second, r)-max(p[i].first, l);
        if(k >= 0 && can) {
            l = min(l, p[i].first), r = max(r, p[i].second);
        } else if(p[i].first <= x && x <= p[i].second) {
            if(can) a.push_back({ l, r });
            can = true;
            l = p[i].first, r = p[i].second;
        }
    }

    if(can) a.push_back({ l, r });
    if(a.empty()) return void(cout << 1 << '\n');

    sort(a.begin(), a.end());

    int ans = 0;
    l = a[0].first, r = a[0].second;

    for(int i = 0; i+1 < a.size(); i++) {
        if(a[i].second >= a[i+1].first) {
            l = min(l, a[i+1].first), r = max(r, a[i+1].second);
        } else {
            ans += r-l+1;
            l = a[i+1].first, r = a[i+1].second;
        }
    }

    ans += r-l+1;

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