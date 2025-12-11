#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, a; cin >> n >> a;
    int less = 0, more = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x < a) less++;
        if(x > a) more++;
    }

    cout << (less > more ? a-1 : a+1) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}