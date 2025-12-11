#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), cnt(32);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[bit_width((unsigned int)a[i])]++;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        cnt[bit_width((unsigned int)a[i])]--;
        ans += cnt[bit_width((unsigned int)a[i])];
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}