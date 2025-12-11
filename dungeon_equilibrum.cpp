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

    vector<int> cnt(n+1);
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int ans = 0;

    for(int i = 0; i <= n; i++) {
        if(!cnt[i]) continue;
        if(cnt[i] == i) continue;
        else if(cnt[i] > i) ans += cnt[i]-i;
        else ans += cnt[i];
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