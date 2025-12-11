#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string t; cin >> t;

    int ans = 0;

    vector<bool> b(n+1);

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j += i+1) {
            if(t[j] == '1') break;
            if(!b[j+1]) {
                ans += i+1;
                b[j+1] = 1;
            }
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}