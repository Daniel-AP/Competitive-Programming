#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n), cnt(n+1);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    sort(a.begin(), a.end());
    set<int> s(a.begin(), a.end());

    int ans = 1;

    for(int x = 2; x <= n; x++) {
        int need = n;
        for(int i = 1; x*i < 4*x && x*i <= n; i++) need -= cnt[x*i];
        int i = lower_bound(a.begin(), a.end(), 4*x)-a.begin();
        need -= n-i;
        if(need <= k) ans = x;
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