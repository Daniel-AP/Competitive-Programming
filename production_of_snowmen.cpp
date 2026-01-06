#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n), c(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    int cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if(a[j] >= b[(j+i)%n]) ok = false;
        }
        cnt1 += ok;
    }

    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if(b[j] >= c[(j+i)%n]) ok = false;
        }
        cnt2 += ok;
    }

    cout << cnt1*n*cnt2 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}