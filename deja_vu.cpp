#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, q; cin >> n >> q;

    vector<int> a(n), x(q);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i++) cin >> x[i];

    vector<int> xx;
    for(int i = 0; i < q; i++) if(xx.empty() || xx.back() > x[i]) xx.push_back(x[i]);

    for(int k: xx) {
        for(int i = 0; i < n; i++) {
            if(a[i]%(1LL<<k) == 0) {
                a[i] += (1LL<<(k-1));
            }
        }
    }

    for(int x: a) cout << x << ' ';
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