#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int x, n; cin >> x >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    auto cmp = [&](pair<int, int> p1, pair<int, int> p2) {
        return p1.second-p1.first-1 > p2.second-p2.first-1;
    };

    multiset<int> ms = { 0, x };
    multiset<pair<int, int>, decltype(cmp)> pp(cmp);

    pp.insert({ 0, x });

    for(int i = 0; i < n; i++) {

        auto it1 = prev(ms.upper_bound(p[i]));
        auto it2 = ms.upper_bound(p[i]);

        pp.erase(pp.find({ *it1, *it2 }));
        pp.insert({ *it1, p[i] });
        pp.insert({ p[i], *it2 });
        ms.insert(p[i]);

        auto [l, r] = *pp.begin();

        cout << r-l << ' ';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}