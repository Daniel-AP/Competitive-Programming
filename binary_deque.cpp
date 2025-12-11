#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, s; cin >> n >> s;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = count(a.begin(), a.end(), 1);

    if(s == cnt) return void(cout << 0 << '\n');
    if(s > cnt) return void(cout << -1 << '\n');

    vector<int> b1(n+1), b2(n+1);
    b1[1] = a[0], b2[1] = a[n-1];

    for(int i = 2; i <= n; i++) {
        b1[i] = b1[i-1]+a[i-1];
    }

    for(int i = 2; i <= n; i++) {
        b2[i] = b2[i-1]+a[n-i];
    }

    int ans = INF, diff = cnt-s;

    for(int i = 0; i <= diff; i++) {

        int j1 = lower_bound(b1.begin(), b1.end(), i)-b1.begin();
        int j2 = lower_bound(b2.begin(), b2.end(), diff-i)-b2.begin();

        ans = min(ans, j1+j2);

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}