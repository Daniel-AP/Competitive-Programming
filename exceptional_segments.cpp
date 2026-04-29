#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;
    int ans = 0;

    int c1 = (((x-1-3)/4+1)%MOD+1)%MOD;
    c1 *= (((n-3)/4+1)%MOD-((x-1-3)/4+1)%MOD+MOD)%MOD;
    c1 %= MOD;

    if(x >= 4) ans += c1;
    else if(n >= 3) ans += ((n-3)/4+1)%MOD;
    ans %= MOD;

    int c2 = ((x-1-1)/4+1)%MOD;
    c2 *= (((n-1)/4+1)%MOD-((x-1-1)/4+1)%MOD+MOD)%MOD;
    c2 %= MOD;

    if(x >= 2) ans += c2;
    ans %= MOD;

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