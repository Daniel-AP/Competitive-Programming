#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    map<int, int> cntB, cnt;
    int cur = 0, ans = 0;

    for(int i = 0; i < m; i++) cntB[b[i]]++;

    for(int i = 0; i < m; i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] <= cntB[a[i]]) cur++;
    }

    for(int i = 0; i+m-1 < n; i++) {
        if(cur >= k) ans++;
        cnt[a[i]]--;
        if(cnt[a[i]] < cntB[a[i]]) cur--;
        if(i+m < n) cnt[a[i+m]]++;
        if(i+m < n && cnt[a[i+m]] <= cntB[a[i+m]]) cur++;
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