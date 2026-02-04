#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int mnA = INF, mxA = -INF;

    vector<int> mnB(n), mxB(n);
    mnB[n-1] = mxB[n-1] = b[n-1];

    for(int i = n-2; i >= 0; i--) {
        mnB[i] = min(mnB[i+1], b[i]);
        mxB[i] = max(mxB[i+1], b[i]);
    }

    map<int, int> mp;

    for(int i = 0; i < n; i++) {
        mnA = min(mnA, a[i]), mxA = max(mxA, a[i]);
        int l = min(mnA, mnB[i]), r = max(mxA, mxB[i]);
        if(mp.find(l) == mp.end()) mp[l] = max(r, l);
        else mp[l] = min(mp[l], max(r, l));
    }

    int ans = 0, mn = INF;

    for(int i = 2*n; i >= 1; i--) {
        if(mp.find(i) != mp.end()) mn = min(mn, mp[i]);
        if(mn != INF) ans += 2*n-max(i, mn)+1;
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