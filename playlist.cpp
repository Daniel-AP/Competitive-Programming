#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> k(n);
    for(int i = 0; i < n; i++) cin >> k[i];

    map<int, int> mp;

    int ans = 1, l = 0;

    for(int i = 0; i < n; i++) {
        if(mp.find(k[i]) != mp.end()) {
            ans = max(ans, i-l);
            for(int j = l; j < mp[k[i]]; j++) mp.erase(k[j]);
            l = mp[k[i]]+1;
        }
        mp[k[i]] = i;
    }

    ans = max(ans, (n-1)-l+1);

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}