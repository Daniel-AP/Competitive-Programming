#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> b(n-1);
    for(int i = 0; i < n-1; i++) cin >> b[i];

    vector<int> a(n);
    a[0] = b[0], a[n-1] = b.back();

    for(int i = 1; i < n-1; i++) {
        a[i] = min(b[i-1], b[i]);
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