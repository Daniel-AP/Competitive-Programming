#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, q; cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> k(q);
    for(int i = 0; i < q; i++) cin >> k[i];

    vector<int> mx(n), prefix(n+1);
    mx[0] = a[0];

    for(int i = 1; i < n; i++) mx[i] = max(mx[i-1], a[i]);
    partial_sum(a.begin(), a.end(), prefix.begin()+1);

    for(int i = 0; i < q; i++) {
        int j = upper_bound(mx.begin(), mx.end(), k[i])-mx.begin();
        cout << prefix[j] << ' ';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}