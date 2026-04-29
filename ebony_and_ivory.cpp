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

void shift(int& x, int& y, int a, int b, int k) {
    x += b*k;
    y -= a*k;
}

void solve() {

    int a, b, c; cin >> a >> b >> c;
    
    auto [g, x, y] = ext_gcd(abs(a), abs(b));

    if(c % g != 0) return void(cout << "No" << '\n');

    x *= c/g;
    y *= c/g;

    if(a < 0) x *= -1;
    if(b < 0) y *= -1;

    a /= g, b /= g;

    int l = ceil(double(-x)/b);
    int r = floor(double(y)/a);

    cout << (l > r ? "No" : "Yes") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}