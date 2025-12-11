#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), c(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) c[i] = a[i];

    if(n == 1) return void(cout << 0 << '\n');

    vector<array<int, 3>> ops;
    vector<pair<int, int>> b(n);

    b[n-2] = { n-2, n-1 };
    int mxi = (a[n-2] > a[n-1] ? n-2 : n-1);

    for(int i = n-3; i >= 0; i--) {
        b[i] = { i, mxi };
        mxi = (a[i] > a[mxi] ? i : mxi);
    }

    pair<int, int> best = b[n-2];

    for(int i = n-3; i >= 0; i--) {
        if(a[best.first]-a[best.second] <= c[i+1]) {
            ops.push_back({ i+1, best.first+1, best.second+1 });
            c[i] = a[best.first]-a[best.second];
        } else if(c[i] > c[i+1]) return void(cout << -1 << '\n');
        if(a[b[i].first]-a[b[i].second] < a[best.first]-a[best.second]) {
            best = b[i];
        }
    }

    if(!is_sorted(c.begin(), c.end())) return void(cout << -1 << '\n');

    cout << ops.size() << '\n';

    reverse(ops.begin(), ops.end());
    
    for(int i = 0; i < ops.size(); i++) {
        cout << ops[i][0] << ' ' << ops[i][1] << ' ' << ops[i][2] << '\n';
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}