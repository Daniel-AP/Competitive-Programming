#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int a, b, c;

    if((n&1) || popcount(n) == 1) return void(cout << -1 << '\n');

    int s, i = 0;
    while(i < 64 && ((n/2)&(1ULL<<i)) == 0) i++;
    s = (1ULL<<i);

    a = (n^s), b = n/2, c = n/2-s;

    cout << a << ' ' << b << ' ' << c << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}