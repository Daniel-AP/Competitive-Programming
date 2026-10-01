#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;

    int l = 0, r = n-1, ans = 0;
    
    while(l < r) {
        if(s[l] != s[r]) {
            if(s[l] == c || s[r] == c) ans++;
            else ans += 2;
        }
        l++, r--;
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