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

int cnt(int n) {
    if(n == 0) return 1;
    int ans = 0;
    while(n > 0) ans++, n /= 10;
    return ans;
}

void solve() {

    long double n, k; cin >> n >> k;
    long double x = k*log10l(n);

    int f = powl((long double)10, x-floorl(x)+2);
    int l = binpow(n, k, 1000);

    cout << f << "..." << string(3-cnt(l), '0') << l << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}