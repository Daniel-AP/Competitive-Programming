#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    int cnt = count(b.begin(), b.end(), 0);

    int s = 0;
    for(int i = 0; i < n; i++) s += b[i];

    cout << min(s+1-n, n-cnt) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}