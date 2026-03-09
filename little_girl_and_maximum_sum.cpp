#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, q; cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    vector<int> diff(n+1);

    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        diff[l]++;
        if(r+1 <= n) diff[r+1]--;
    }

    vector<int> cnt(n);
    int cur = 0;

    for(int i = 1; i <= n; i++) {
        cur += diff[i];
        cnt[i-1] = cur;
    }

    sort(all(cnt));

    int ans = 0;

    for(int i = n-1; i >= 0; i--) {
        ans += cnt[i]*a[i];
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