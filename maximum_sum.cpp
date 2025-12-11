#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> px(n+1);
    partial_sum(a.begin(), a.end(), px.begin()+1);

    int ans = 0, tot = px[n];

    for(int i = 0; i <= k; i++) {
        ans = max(ans, tot-px[i*2]-(px[n]-px[n-(k-i)]));
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