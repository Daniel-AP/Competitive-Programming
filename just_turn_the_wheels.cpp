#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int c, f, b, s; cin >> c >> f >> b >> s;

    int turns = 1;
    turns *= 12/gcd(turns*f, 12);
    turns *= 12/gcd(turns*b, 12);

    int ans = ((12*s+c-1)/c+turns-1)/turns*turns;
    
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