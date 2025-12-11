#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt = 0, l = -1, r = -1;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') continue;
        if(r >= i) r = min(n-1, i+k);
        else {
            if(l != -1) cnt += r-l+1;
            l = i, r = min(n-1, i+k);
        }
    }

    if(l != -1) cnt += r-l+1;

    cout << n-cnt << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}