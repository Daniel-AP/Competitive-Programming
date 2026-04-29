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

// to get solutions, iterate x = lx+k*(b/g) for all k >= 0 until x = rx
int countSols(int a, int b, int c, int x1, int x2, int y1, int y2) {

    if(a == 0 && b == 0) {
        if(c == 0) return (x2-x1+1)*(y2-y1+1);
        return 0;
    }

    if(a == 0) {
        if(c % b != 0) return 0;

        int y = c / b;

        if(y < y1 || y > y2) return 0;
        return x2 - x1 + 1;
    }

    if(b == 0) {
        if(c % a != 0) return 0;

        int x = c / a;

        if(x < x1 || x > x2) return 0;
        return y2 - y1 + 1;
    }

    auto [g, x, y] = ext_gcd(abs(a), abs(b));

    if(c % g != 0) return 0;

    x *= c / g;
    y *= c / g;

    if(a < 0) x *= -1;
    if(b < 0) y *= -1;

    a /= g;
    b /= g;

    int signA = a > 0 ? 1 : -1;
    int signB = b > 0 ? 1 : -1;

    shift(x, y, a, b, (x1 - x) / b);

    if(x < x1) shift(x, y, a, b, signB);
    if(x > x2) return 0;

    int lx1 = x;

    shift(x, y, a, b, (x2 - x) / b);

    if(x > x2) shift(x, y, a, b, -signB);

    int rx1 = x;

    shift(x, y, a, b, -(y1 - y) / a);

    if(y < y1) shift(x, y, a, b, -signA);
    if(y > y2) return 0;

    int lx2 = x;

    shift(x, y, a, b, -(y2 - y) / a);

    if(y > y2) shift(x, y, a, b, signA);

    int rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);

    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if(lx > rx) return 0;

    return (rx-lx) / abs(b) + 1;

}

void solve() {

    int a, b, c; cin >> a >> b >> c;
    int x1, x2; cin >> x1 >> x2;
    int y1, y2; cin >> y1 >> y2;

    cout << countSols(a, b, -c, x1, x2, y1, y2) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}