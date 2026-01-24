#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> c(n+1), bad(n+1);
    
    for(int i = 1; i <= n; i++) {
        int pi, ci; cin >> pi >> ci;
        if(pi != -1) bad[pi] |= (ci==0);
        c[i] = ci;
    }

    bool one = false;

    for(int i = 1; i <= n; i++) {
        if(c[i] == 0 || bad[i]) continue;
        one = true;
        cout << i << ' ';
    }

    if(!one) cout << -1;

    cout << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}