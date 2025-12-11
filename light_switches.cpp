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

    vector<int> diff(2*k+1), inter(2*k);

    for(int i = 0; i < n; i++) {
        int l = a[i]%(2*k), r = (a[i]+k-1)%(2*k);
        if(l <= r) diff[l]++, diff[r+1]--;
        else diff[l]++, diff[2*k]--, diff[0]++, diff[r+1]--;
    }

    inter[0] = diff[0];
    for(int i = 1; i < 2*k; i++) inter[i] = inter[i-1]+diff[i];

    int ans = INF;
    int mx = *max_element(a.begin(), a.end());

    for(int i = 0; i < 2*k; i++) {
        if(inter[i] == n) {
            int r = mx%(2*k);
            int rr = (i-r+2*k)%(2*k);
            ans = min(ans, mx+rr);
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}