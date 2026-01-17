#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string t, p; cin >> t >> p;
    int n = t.length(), m = p.length();

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;

        string tt = t;
        for(int i = 0; i < mid; i++) tt[a[i]-1] = '#';

        int i = 0, j = 0;

        while(i < n && j < m) {
            if(tt[i] == p[j]) j++;
            i++;
        }

        if(j == m) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }

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