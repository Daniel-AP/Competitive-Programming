#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(31);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 31; j++) {
            if((a[i]&(1<<j))) {
                b[j]++;
            }
        }
    }

    int ans = a[0];

    for(int i = 0; i < n; i++) {
        ans &= a[i];
    }

    for(int i = 30; i >= 0; i--) {
        int need = n-b[i];
        if(need <= k) {
            ans |= (1<<i);
            k -= need;
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