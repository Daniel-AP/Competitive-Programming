#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    multiset<int> b;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        b.insert(x);
    }

    vector<array<int, 3>> c(n);
    for(int i = 0; i < n; i++) {
        c[i] = {a[i]-k, a[i]+k, i};
    }

    sort(all(c));

    vector<int> ans(n);

    for(auto [l, r, i]: c) {
        auto it = b.lower_bound(l);
        ans[i] = *it;
        b.erase(it);
    }

    for(int x: ans) cout << x << ' ';
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