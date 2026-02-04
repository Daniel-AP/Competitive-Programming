#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    map<int, int> cnt;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int ans = 1;

    for(auto [k, v]: cnt) {
        ans *= (1+v);
        ans %= MOD;
    }

    cout << (ans-1)%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}