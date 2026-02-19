#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<long double> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    map<int, int> cnt;

    for(int i = 0; i < n; i++) {
        int x = roundl((a[i]-log2(a[i]))*1e9);
        ans += cnt[x];
        cnt[x]++;
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