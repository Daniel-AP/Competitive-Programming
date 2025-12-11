#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;
    int no = 0;

    multiset<int> a;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    vector<pair<int, int>> nonz, z;
    vector<int> b(m), c(m);

    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < m; i++) cin >> c[i];

    for(int i = 0; i < m; i++) {
        if(c[i] == 0) {
            z.push_back({ b[i], c[i] });
        } else {
            nonz.push_back({ b[i], c[i] });
        }
    }

    sort(nonz.begin(), nonz.end());

    for(int i = 0; i < nonz.size(); i++) {
        auto it = a.lower_bound(nonz[i].first);
        if(it == a.end()) {
            no++;
        } else {
            a.insert(max(*it, nonz[i].second));
            a.erase(it);
        }
    }

    sort(z.rbegin(), z.rend());

    for(int i = 0; i < z.size(); i++) {
        auto it = a.lower_bound(z[i].first);
        if(it == a.end()) {
            no++;
        } else {
            if(z[i].second > 0) a.insert(max(*it, z[i].second));
            a.erase(it);
        }
    }

    cout << m-no << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}