#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int s(int l, int r) {

    if(l > r) return 0;

    return (r-l+1)*(r+l)/2;

}

void solve() {

    int n, m; cin >> n >> m;
    int mx = 0;

    map<int, int> cnt;

    for(int i = 0; i < n; i++) {

        int l; cin >> l;

        vector<int> a(l);
        for(int j = 0; j < l; j++) cin >> a[j];

        map<int, bool> has;
        for(int j = 0; j < l; j++) has[a[j]] = 1;

        int q1 = 0, q2 = 0;

        for(; q1 <= l; q1++) {
            if(!has[q1]) break;
        }

        q2 = q1+1;

        for(; q2 <= l; q2++) {
            if(!has[q2]) break;
        }

        mx = max(mx, q2);
        cnt[q1]++;

    }

    int ans = (mx+(cnt[mx]>0))*min(mx+(cnt[mx]>0)+1, m+1)+s(mx+(cnt[mx]>0)+1, m);

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