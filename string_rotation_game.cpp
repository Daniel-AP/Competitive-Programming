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

    int ans = 0, cur = 0, mx = 0;
    char prev = s[0];

    for(int i = 0; i < n; i++) {
        if(s[i] != prev) {
            ans++;
            cur = 1;
        } else {
            cur++;
            mx = max(mx, cur);
        }
        prev = s[i];
    }

    ans++;

    if(s[0] != s.back() && mx > 1) ans++;

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