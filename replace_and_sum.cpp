#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, q; cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> c(n);
    c[n-1] = max(b[n-1], a[n-1]);

    for(int i = n-2; i >= 0; i--) {
        c[i] = max({c[i+1], a[i], b[i]});
    }

    vector<int> px(n+1);
    partial_sum(all(c), px.begin()+1);

    while(q--) {

        int l, r; cin >> l >> r;

        cout << px[r]-px[l-1] << ' ';

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