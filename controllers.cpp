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
    return {g, y-b/a*x, x};
}

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int neg = 0, pos = 0;

    for(int i = 0; i < n; i++) {
        neg += (s[i]=='-');
        pos += (s[i]=='+');
    }

    int q; cin >> q;

    while(q--) {

        int a, b; cin >> a >> b;
        int mx = max(a, b), mn = min(a, b);

        if(a == b) {
            cout << (pos == neg ? "YES" : "NO") << '\n';
            continue;
        }

        bool bad = false;
        int d = abs(pos*mn-neg*mn);

        bad |= (d%(mx-mn) != 0);
        bad |= (d/(mx-mn) > min(pos, neg));

        cout << (bad ? "NO" : "YES") << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}