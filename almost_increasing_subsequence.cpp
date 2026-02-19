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

    int l = 0, cur = 1;

    vector<pair<int, int>> seg;

    for(int i = 0; i < n; i++) {
        if(i-1 >= 0 && a[i-1] >= a[i]) cur++;
        else {
            if(cur > 1) seg.push_back({ l, l+cur-1 });
            cur = 1;
            l = i;
        }
    }

    if(cur > 1) seg.push_back({ l, l+cur-1 });

    int m = seg.size();

    vector<int> px(m+1);
    for(int i = 1; i <= m; i++) px[i] = px[i-1]+(seg[i-1].second-seg[i-1].first-1);
    
    while(q--) {

        int l, r; cin >> l >> r;
        int ans = r-l+1;

        int i1 = lower_bound(all(seg), make_pair(l, 0LL))-seg.begin()-1;
        int i2 = upper_bound(all(seg), make_pair(r, 0LL))-seg.begin()-1;

        if(i1 >= 0) ans -= max(min(seg[i1].second+1, r)-max(seg[i1].first+1, l)-1, 0LL);
        if(i2 > i1) ans -= max(min(seg[i2].second+1, r)-max(seg[i2].first+1, l)-1, 0LL);

        int ll = i1+1, rr = i2;

        if(ll <= rr) ans -= px[rr]-px[ll];

        cout << ans << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}