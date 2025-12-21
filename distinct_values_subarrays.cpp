#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    map<int, int> mp;

    int ans = 0, l = 0;

    for(int i = 0; i < n; i++) {
        
        if(mp.find(x[i]) != mp.end()) {
            for(int j = l; j < mp[x[i]]; j++) mp.erase(x[j]);
            l = mp[x[i]]+1;
        }

        mp[x[i]] = i;
        ans += i-l+1;

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