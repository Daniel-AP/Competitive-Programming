#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    vector<int> divs;

    for(int i = 1; i*i <= n; i++) {
        if(n%i != 0) continue;
        divs.push_back(i);
        if(n/i != i) divs.push_back(n/i);
    }

    int ans = n;

    for(int d: divs) {
        if(d == n) continue;

        string k1 = s.substr(0, d);
        string k2 = s.substr(d, d);

        int miss = 0;

        for(int i = 0; i < n; i++) {
            miss += (s[i] != k1[i%d]);
        }

        if(miss <= 1) {
            ans = min(ans, d);
            continue;
        }

        miss = 0;

        for(int i =0; i < n; i++) {
            miss += (s[i] != k2[i%d]);
        }

        if(miss <= 1) {
            ans = min(ans, d);
            continue;
        }

    }

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