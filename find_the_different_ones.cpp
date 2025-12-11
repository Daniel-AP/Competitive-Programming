#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> diff;
    for(int i = 0; i+1 < n; i++) {
        if(a[i] != a[i+1]) diff.push_back(i+1);
    }

    int q; cin >> q;

    while(q--) {

        int l, r; cin >> l >> r;
        int i = lower_bound(diff.begin(), diff.end(), l)-diff.begin();

        int x = -1, y = -1;

        if(i < diff.size() && diff[i]+1 <= r) x = diff[i], y = diff[i]+1;

        cout << x << ' ' << y << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}