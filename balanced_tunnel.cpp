#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> mp;
    for(int i = 0; i < n; i++) mp[a[i]] = i;

    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> c(n);
    for(int i = 0; i < n; i++) c[i] = mp[b[i]];

    int ans = 0, mn = c[n-1];

    for(int i = n-2; i >= 0; i--) {
        if(mn < c[i]) ans++;
        mn = min(mn, c[i]);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}