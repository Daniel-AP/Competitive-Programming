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

void solve(int b, int p, int m) {

    cout << binpow(b, p, m) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int b, p, m;
    while(cin >> b >> p >> m) solve(b, p, m);

    return 0;

}