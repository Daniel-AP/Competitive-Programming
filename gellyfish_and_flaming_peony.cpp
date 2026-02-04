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

    int g = 0;
    for(int i = 0; i < n; i++) g = gcd(g, a[i]);

    for(int i = 0; i < n; i++) a[i] /= g;

    if(count(all(a), 1)) return void(cout << n-count(all(a), 1) << '\n');

    vector<int> dp(5000+1, INF);
    dp[1] = 0;

    for(int i = 2; i <= 5000; i++) {
        for(int x: a) {
            dp[i] = min(1+dp[gcd(i, x)], dp[i]);
        }
    }

    int mn = INF;
    for(int x: a) mn = min(mn, dp[x]);

    cout << mn+n-1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}