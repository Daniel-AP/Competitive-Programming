#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

map<int, int> factors(int n) {

    map<int, int> f;

    while(n%2 == 0) {
        f[2]++;
        n /= 2;
    }

    while(n%3 == 0) {
        f[3]++;
        n /= 3;
    }

    for(int i = 5; i*i <= n; i += 6) {
        while(n%i == 0) {
            f[i]++;
            n /= i;
        }
        while(n%(i+2) == 0) {
            f[i+2]++;
            n /= i+2;
        }
    }

    if(n > 1) f[n]++;

    return f;

}

void solve() {

    int n; cin >> n;

    map<int, int> f = factors(n);

    if(f.size() == 1) {
        auto [k, v] = *f.begin();
        if(v >= 6) {
            cout << "YES" << '\n';
            cout << k << ' ' << k*k << ' ' << n/(k*k*k) << '\n';
        } else {
            cout << "NO" << '\n';
        }
        return;
    }

    auto [k1, v1] = *f.begin();
    auto [k2, v2] = *(++f.begin());

    set<int> ans = { k1, k2, n/(k1*k2) };

    if(ans.size() != 3 || *ans.begin() == 1) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        for(int x: ans) cout << x << ' ';
        cout << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}