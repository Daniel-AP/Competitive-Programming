#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, l, r; cin >> n >> l >> r;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    int lp = 0, rp = n-1;
    int ans = 0;

    while(lp < rp && !((a[lp] < l) && (a[rp] < l) || (a[lp] > r) && (a[rp] > r))) {
        ans += a[rp--]-a[lp++];
    }

    while(lp <= rp) {
        if(a[rp] < l) ans += l-a[rp];
        else if(a[rp] > r) ans += a[rp]-r;
        rp--;
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