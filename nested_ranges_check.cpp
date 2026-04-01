#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> rngs(n);

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        rngs[i] = {x, y};
    }

    vector<int> ind(n);
    iota(all(ind), 0);

    sort(all(ind), [&](int i, int j) {
        if(rngs[i].first != rngs[j].first) return rngs[i].first < rngs[j].first;
        return rngs[i].second > rngs[j].second;
    });

    vector<int> ans1(n);

    int mn = INF;

    for(int i = n-1; i >= 0; i--) {
        int j = ind[i];
        ans1[j] = (mn<=rngs[j].second);
        mn = min(mn, rngs[j].second);
    }

    int mx = 0;

    vector<int> ans2(n);

    for(int i: ind) {
        ans2[i] = (mx>=rngs[i].second);
        mx = max(mx, rngs[i].second);
    }

    for(int x: ans1) cout << x << ' ';
    cout << '\n';
    for(int x: ans2) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}