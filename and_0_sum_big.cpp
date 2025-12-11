#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }

    return ans;

}

void solve() {

    int n, k; cin >> n >> k;

    cout << binpow(n, k) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}