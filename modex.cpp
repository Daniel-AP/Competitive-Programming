#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int binpow(int a, int b, int mod) {

    a %= mod;

    int ans = 1;

    while(b) {
        if(b%2) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b /= 2;
    }

    return ans;
    
}

void solve() {

    int x, y, n; cin >> x >> y >> n;

    cout << binpow(x, y, n) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}