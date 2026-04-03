#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int binpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b%2) ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}

void solve() {

    int n; cin >> n;
    int ans = 4*2*3*binpow(4, n-3);

    if(n > 3) ans += 4*3*3*binpow(4, n-4)*(n-3);

    cout << ans;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}