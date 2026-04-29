#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

array<int, 3> ext_gcd(int a, int b) {
    if(!a) return {b, 0, 1};
    auto [g, x, y] = ext_gcd(b%a, a);
    return {g, y - b/a*x, x};
}

void solve(int t) {

    int a, b, c; cin >> a >> b >> c;

    auto [g, x, y] = ext_gcd(a, b);

    cout << "Case " << t << ": ";
    if(c%g != 0) cout << "No";
    else cout << "Yes";
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    for(int tt = 1; tt <= t; tt++) solve(tt);

    return 0;

}