#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> no(n);
    for(int i = 0; i+1 < n; i++) {
        no[i+1] = (a[i]>=2*a[i+1]);
    }

    vector<int> px(n);
    partial_sum(no.begin()+1, no.end(), px.begin()+1);

    int ans = 0;

    for(int i = k; i < n; i++) {
        ans += (px[i]-px[i-k] == 0);
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