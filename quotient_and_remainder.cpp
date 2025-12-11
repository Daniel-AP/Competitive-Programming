#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> q(n), r(n);

    for(int i = 0; i < n; i++) cin >> q[i];
    for(int i = 0; i < n; i++) cin >> r[i];

    sort(q.rbegin(), q.rend());
    sort(r.begin(), r.end());

    int curQ = 0, curR = 0, ans = 0;

    while(curQ < n && curR < n) {
        int y = r[curR]+1;
        int x = q[curQ]*y+r[curR];
        if(x > y && x <= k) ans++, curR++;
        curQ++;
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