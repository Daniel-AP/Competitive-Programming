#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> a(n);

    map<int, vector<int>> mp;
    map<int, int> val;

    for(int i = 0; i < n; i++) {
        mp[b[i]].push_back(i);
    }

    int last = 0;

    while(mp.size() >= 2) {
        auto [k1, v1] = *mp.begin();
        mp.erase(mp.begin());
        auto [k2, v2] = *mp.begin();
        int diff = k2-k1;
        if(diff%v1.size() != 0) return void(cout << -1 << '\n');
        val[k1] = diff/v1.size();
        last = diff/v1.size();
    }

    if(!mp.empty()) {
        auto [k1, v1] = *mp.begin();
        mp.erase(mp.begin());
        val[k1] = last+1;
    }

    for(int i = 0; i < n; i++) {
        a[i] = val[b[i]];
    }

    map<int, pair<int, int>> check;

    for(int i = 0; i < n; i++) {
        if(check.find(a[i]) == check.end()) {
            check[a[i]] = {0, 0};
        }
        check[a[i]].first += a[i];
        check[a[i]].second = b[i];
    }

    int cur = 0;

    for(auto [k, v]: check) {
        if(cur != v.second) return void(cout << -1 << '\n');
        cur += v.first;
    }

    for(int x: a) cout << x << ' ';
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