#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<int> p;

void pre() {

    int cur = 1, f = 1;

    while(cur <= 1e12) p.push_back(cur), cur *= ++f;

}

void solve() {

    int n; cin >> n;
    int m = p.size();

    int ans = INF;

    for(int i = 0; i < (1<<m); i++) {
        int cand = 0;
        for(int j = 0; j < m; j++) {
            if((i&(1<<j))) cand += p[j];
        }
        if(cand > n) continue;
        if(((n-cand)&1) && (i&1) || ((n-cand)&2) && (i&2)) continue;
        ans = min(ans, (int)(popcount(i)+popcount(n-cand)));
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}