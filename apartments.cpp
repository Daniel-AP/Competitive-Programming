#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    multiset<int> b;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        b.insert(x);
    }

    sort(a.begin(), a.end());

    int ans = 0;

    for(int i = 0; i < n; i++) {
        auto it = b.lower_bound(a[i]-k);
        if(it == b.end()) continue;
        if(*it > a[i]+k) continue;
        ans++;
        b.erase(it);
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