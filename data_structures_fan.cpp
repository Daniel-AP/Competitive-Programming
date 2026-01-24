#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    string s; cin >> s;
    int q; cin >> q;

    int z = 0, o = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            z ^= a[i];
        } else {
            o ^= a[i];
        }
    }

    vector<int> px(n+1);
    for(int i = 1; i <= n; i++) px[i] = (px[i-1]^a[i-1]);

    while(q--) {

        int op; cin >> op;

        if(op == 1) {
            int l, r; cin >> l >> r;
            z ^= (px[r]^px[l-1]);
            o ^= (px[r]^px[l-1]);
        } else {
            int g; cin >> g;
            cout << (g == 0 ? z : o) << ' ';
        }

    }

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