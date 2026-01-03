#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve(int n) {

    int ans = 0;

    for(int i = 2; n-i > 1; i++) {
        int rng = n-i, j = min(rng-1, i-1);
        ans += j*rng-j*(j+1)/2;
    }
    
    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true) {
        int n; cin >> n;
        if(n < 3) break;
        solve(n);
    }

    return 0;

}