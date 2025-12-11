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

    while(q--) {

        int x; cin >> x;

        if(!binary_search(a.begin(), a.end(), x)) {
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }

        int i1 = lower_bound(a.begin(), a.end(), x)-a.begin();
        int i2 = upper_bound(a.begin(), a.end(), x)-a.begin()-1;

        cout << i1+1 << ' ' << i2+1 << '\n';
        
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}