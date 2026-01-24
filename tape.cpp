#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, k; cin >> n >> m >> k;

    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> diff(n-1);
    for(int i = 0; i < n-1; i++) diff[i] = b[i+1]-b[i];

    sort(diff.rbegin(), diff.rend());

    int ans = k-1;

    for(int i = k-1; i < n-1; i++) ans += diff[i];
    
    cout << ans+1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}