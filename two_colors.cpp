#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++) a[i] = min(a[i], n-1);

    vector<int> px(m+1);
    partial_sum(a.begin(), a.end(), px.begin()+1);

    int ans = 0;

    for(int i = 0; i < m; i++) {

        int j = lower_bound(a.begin()+i+1, a.end(), n-a[i])-a.begin()+1;

        if(j > m) continue;

        int d = m-j+1;

        ans += 2*(a[i]*d+(px[m]-px[j-1])-n*d+d);

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