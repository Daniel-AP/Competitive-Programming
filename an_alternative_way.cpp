#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    if(b[0] < a[0]) return void(cout << "NO" << '\n');

    for(int i = n-1; i > 0; i--) {
        if(a[i] <= b[i]) {
            a[i] = b[i];
            continue;
        }
        if(b[i] < a[i]) a[i-1] += a[i]-b[i], a[i] = b[i];
    }

    if(b[0] > a[0]) a[0] = b[0];

    if(a == b) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}