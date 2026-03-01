#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, h, k; cin >> n >> h >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i];

    int ans = 0;

    if(h%s == 0) return void(cout << h/s*n+(h/s-1)*k << '\n');

    ans += (h/s)*(n+k);
    h %= s;

    vector<int> px(n+1);
    partial_sum(all(a), px.begin()+1);

    vector<int> mn(n), mx(n);
    mn[0] = a[0], mx[n-1] = a[n-1];

    for(int i = 1; i < n; i++) mn[i] = min(mn[i-1], a[i]);
    for(int i = n-2; i >= 0; i--) mx[i] = max(mx[i+1], a[i]);

    int l = 0, r = n-2, mid, anss = n-1;

    while(l <= r) {
        mid = l+(r-l)/2;
        int ss = px[mid+1];
        if(mn[mid] < mx[mid+1]) {
            ss -= mn[mid];
            ss += mx[mid+1];
        }
        if(ss >= h) {
            anss = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    ans += anss+1;

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