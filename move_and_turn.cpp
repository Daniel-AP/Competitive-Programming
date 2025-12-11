#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    if(n == 1 || n == 2) cout << 4 << '\n';
    else if(n%2 == 0) cout << (n/2+1)*(n/2+1) << '\n';
    else if(n%2 == 1) cout << 12+((n-3)/2)*(24+4*((n-5)/2))/2 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}