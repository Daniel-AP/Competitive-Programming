#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(n-1);
    for(int i = 0; i+1 < n; i++) b[i] = a[i+1]-a[i];

    int ans = 0;

    for(int i = 0; i < n-1; i++) {
        if(b[i] < 0) {
            int x = -b[i];
            ans = max(ans, (int)bit_width((unsigned int)x));
            if(i+1 < n-1) b[i+1] -= x;
        }
    }

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