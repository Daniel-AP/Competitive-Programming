#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<pair<int, int>> lr(m);
    for(int i = 0; i < m; i++) cin >> lr[i].first >> lr[i].second;

    int q; cin >> q;

    vector<int> ch(q);
    for(int i = 0; i < q; i++) cin >> ch[i];

    int l = 0, r = q-1, mid, ans = -1;

    while(l <= r) {
        mid = l+(r-l)/2;
        vector<int> chcur(mid+1);
        for(int i = 0; i <= mid; i++) chcur[i] = ch[i];
        sort(all(chcur));
        vector<int> cnt(m);
        for(int i = 0; i < m; i++) {
            cnt[i] = upper_bound(all(chcur), lr[i].second)-chcur.begin()-(lower_bound(all(chcur), lr[i].first)-chcur.begin());
        }
        bool ok = false;
        for(int i = 0; i < m; i++) {
            int len = lr[i].second-lr[i].first+1;
            if(cnt[i] >= len/2+1) ok = true;
        }
        if(ok) {
            ans = mid+1;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}