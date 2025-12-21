#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());

    int l = 0, r = n-1, ans = 0;

    while(l < r) {
        if(p[l]+p[r] <= x) l++;
        ans++;
        r--;
    }

    ans += (l==r);

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}