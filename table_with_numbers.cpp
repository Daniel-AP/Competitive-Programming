#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, h, l; cin >> n >> h >> l;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] <= h) cnt1++;
        if(a[i] <= l) cnt2++;
    }

    int d = abs(cnt1-cnt2);
    int has = min(cnt1, cnt2);

    int ans = 0;
    int t = min(has, d);

    ans += t;
    has -= t;

    ans += has/2;

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