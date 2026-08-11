#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

int binpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return ans;
}

void solve() {

    int n, m, r, c; cin >> n >> m >> r >> c;

    cout << binpow(2, m*(r-1)+n*(c-1)-(r-1)*(c-1)) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}