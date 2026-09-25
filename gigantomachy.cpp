#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int sa = a.back(), sb = b.back();

    for(int i = n-2; i >= 0; i--) {
        sa += a[i]-a[i+1]+1;
    }

    for(int i = m-2; i >= 0; i--) {
        sb += b[i]-b[i+1]+1;
    }

    cout << (sa >= sb ? 1 : 2) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}