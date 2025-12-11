#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, q; cin >> n >> q;

    vector<int> a(n), px0(n+1), px1(n+1);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) px0[i] = px0[i-1]+(a[i-1]==0);
    for(int i = 1; i <= n; i++) px1[i] = px1[i-1]+(a[i-1]==1);

    vector<int> h;
    for(int i = 0; i+1 < n; i++) {
        if(a[i] == a[i+1]) {
            h.push_back(i+1);
        }
    }

    while(q--) {

        int l, r; cin >> l >> r;
        int s0 = px0[r]-px0[l-1], s1 = px1[r]-px1[l-1];

        if(s0%3 || s1%3) {
            cout << -1 << '\n';
            continue;
        }

        int i = lower_bound(h.begin(), h.end(), l)-h.begin();

        if(i == h.size() || h[i]+1 > r) {
            cout << s0/3+s1/3+1 << '\n';
        } else {
            cout << s0/3+s1/3 << '\n';
        }

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}