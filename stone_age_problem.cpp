#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, q; cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i];

    map<int, int> diff;

    for(int i = 0; i < n; i++) {
        diff[i] = a[i];
    }

    int base = 0;

    while(q--) {

        int t; cin >> t;

        if(t == 1) {
            int i, x; cin >> i >> x;
            i--;
            int d = x-base;
            s += d-diff[i];
            diff[i] = d;
        } else {
            int x; cin >> x;
            diff.clear();
            base = x;
            s = 0;
        }

        cout << base*n+s << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}