#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = a[0]-x, r = a[0]+x, ans = 0;

    for(int i = 1; i < n; i++) {
        int ll = max(l, a[i]-x), rr = min(r, a[i]+x);
        if(ll > rr) ans++, l = a[i]-x, r = a[i]+x;
        else l = ll, r = rr;
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