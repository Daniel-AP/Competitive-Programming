#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> ans(m);

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        ans[b]++;
        ans[a]--;
    }

    for(int x: ans) cout << x << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}