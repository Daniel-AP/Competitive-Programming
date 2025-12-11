#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, vector<int>> mp;

    for(int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }

    int ans = INF;

    for(auto [k, v]: mp) {
        vector<int> d = { v[0], n-v.back()-1 };
        for(int i = 0; i+1 < v.size(); i++) d.push_back(v[i+1]-v[i]-1);
        sort(d.rbegin(), d.rend());
        ans = min(ans, max(d[0]/2, d[1]));
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