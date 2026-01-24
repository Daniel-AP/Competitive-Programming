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

    if(n == 1) return void(cout << 1 << '\n');

    sort(all(a));

    int g = 0;

    for(int i = 0; i < n-1; i++) {
        g = gcd(g, a[i+1]-a[i]);
    }

    int mn = n, ans = 0;

    for(int i = n-1; i >= 1; i--) {
        if(a[i]-g > a[i-1]) {
            mn = min((a[n-1]-(a[i]-g))/g, mn);
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        ans += (a[n-1]-a[i])/g;
    }

    cout << ans+mn << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}