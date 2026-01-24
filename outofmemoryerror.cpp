#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, h; cin >> n >> m >> h;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> b(m), c(m), cur = a, q(n+1);
    int id = 0;

    for(int i = 0; i < m; i++) {
        cin >> b[i] >> c[i];
    }

    for(int i = 0; i < m; i++) {

        if(q[b[i]] != id) {
            q[b[i]] = id;
            cur[b[i]] = a[b[i]];
        }

        cur[b[i]] += c[i];

        if(cur[b[i]] > h) id++;

    }

    for(int i = 1; i <= n; i++) {
        if(q[i] != id) cout << a[i] << ' ';
        else cout << cur[i] << ' ';
    }
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}