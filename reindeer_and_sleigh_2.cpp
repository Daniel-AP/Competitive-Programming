#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++) {
        int w, p; cin >> w >> p;
        a[i] = {w, p};
    }

    sort(a.begin(), a.end(), [&](pair<int, int> p1, pair<int, int> p2) {
        return p1.first+p1.second < p2.first+p2.second;
    });

    int ans = 0, s = 0, w = 0;

    for(int i = 0; i < n; i++) s += a[i].second;
    for(int i = 0; i < n; i++) {
        if(s-a[i].second >= w+a[i].first) {
            ans++;
            s -= a[i].second;
            w += a[i].first;
        }
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