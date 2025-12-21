#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string l, r; cin >> l >> r;
    int n = l.length();

    int i = 0, ans = 0;

    while(i < n && l[i] == r[i]) i++, ans += 2;
    if(i < n && r[i]-l[i] == 1) {
        i++;
        ans++;
        while(i < n && r[i] == '0' && l[i] == '9') i++, ans++;
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