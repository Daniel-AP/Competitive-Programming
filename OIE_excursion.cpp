#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) b[i] = (m-(a[i]+1)%m)%m;

    int mx = 0, cur = 1;

    for(int i = 1; i < n; i++) {
        if(b[i] == b[i-1]) cur++;
        else {
            mx = max(mx, cur);
            cur = 1;
        }
    }

    mx = max(mx, cur);

    if(mx >= m) cout << "NO" << '\n';
    else cout << "YES" << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}