#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();

    if(count(all(s), '1') == n) return void(cout << n*n << '\n');

    s += s;
    
    int cur = 0, cnt = 0;

    for(int i = 0; i < 2*n; i++) {
        if(s[i] == '0') cnt = max(cnt, cur), cur = 0;
        else cur++;
    }

    cnt = max(cnt, cur);

    int ans = cnt;
    int l = 1, r = cnt;

    while(r-l > 1) {
        l++, r--;
        ans = max(ans, l*r);
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