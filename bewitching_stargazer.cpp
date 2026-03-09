#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    auto dfs = [&](auto&& self, int l, int r, int cnt = 0) -> pair<int, int> {
        int sz = r-l+1, m = (r+l)/2, cur = 0;
        if(sz < k) return { cnt, cur };
        if(sz%2) {
            cnt++;
            pair<int, int> x = self(self, l, m-1);
            cnt += x.first*2;
            cur += m+x.second;
            cur += n*x.first-x.second+x.first;
        } else {
            pair<int, int> x = self(self, l, m);
            cnt += x.first*2;
            cur += x.second;
            cur += n*x.first-x.second+x.first;
        }
        return { cnt, cur };
    };

    int ans = dfs(dfs, 1, n).second;

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