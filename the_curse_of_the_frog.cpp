#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;

    vector<array<int, 3>> abc(n);

    for(int i = 0; i < n; i++) {
        cin >> abc[i][0] >> abc[i][1] >> abc[i][2];
    }

    int s = 0;

    for(int i = 0; i < n; i++) {
        s += (abc[i][1]-1)*abc[i][0];
    }

    int mx = 0;
    
    for(int i = 0; i < n; i++) {
        mx = max(mx, abc[i][1]*abc[i][0]-abc[i][2]);
    }

    if(s >= x) return void(cout << 0 << '\n');
    if(mx <= 0) return void(cout << -1 << '\n');

    cout << (x-s+mx-1)/mx << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}