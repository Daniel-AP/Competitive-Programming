#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<bool> has(n+1);

    for(int i = 0; i < n-1; i++) {
        int x; cin >> x;
        has[x] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        if(!has[i]) return void(cout << i << '\n');
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}