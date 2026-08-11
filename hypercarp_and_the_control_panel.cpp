#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b, cnt;
    int cur = 1;

    for(int i = 1; i < n; i++) {
        if(a[i] != a[i-1]) {
            b.push_back(a[i-1]);
            cnt.push_back(cur);
            cur = 1;
        } else cur++;
    }

    b.push_back(a.back());
    cnt.push_back(cur);

    int m = b.size();
    int ans = m;

    for(int i = 0; i+1 < m; i++) {
        if(cnt[i] >= 2 && cnt[i+1] >= 2) ans = max(ans, m+2);
    }

    for(int i = 0; i < m; i++) {
        if(cnt[i] < 2) continue;
        if(i+1 < m && (i+2 >= m || b[i] != b[i+2])) ans = max(ans, m+1);
        if(i-1 >= 0 && (i-2 < 0 || b[i] != b[i-2])) ans = max(ans, m+1);
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