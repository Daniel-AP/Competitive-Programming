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

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i];

    int mx1 = a[0], cur1 = a[0];
    for(int i = 1; i < n-1; i++) cur1 = max(a[i], cur1+a[i]), mx1 = max(mx1, cur1);
    int mx2 = a[1], cur2 = a[1];
    for(int i = 2; i < n; i++) cur2 = max(a[i], cur2+a[i]), mx2 = max(mx2, cur2);
    int mx = max(mx1, mx2);

    cout << (mx >= s ? "NO" : "YES") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}