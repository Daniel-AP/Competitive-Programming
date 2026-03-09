#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    int l = 0, r = 1e9, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;

        int prev = 0;
        vector<bool> has(n);

        for(int i = 1; i <= n; i++) {
            if(s[i-1] == 'B' && a[i] > mid) has[prev] = 1;
            if(s[i-1] == 'R' && a[i] > mid) prev = i;
        }

        int cnt = count(all(has), 1);

        if(cnt <= k) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }

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