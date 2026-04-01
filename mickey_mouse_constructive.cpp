#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int x, y; cin >> x >> y;
    int s = abs(x-y);

    vector<int> ans(x+y);

    for(int i = 0; i < x; i++) ans[i] = 1;
    for(int i = x; i < x+y; i++) ans[i] = -1;

    int val = 0;

    for(int i = 1; i*i <= s; i++) {
        if(s%i == 0) {
            val++;
            if(s/i != i) val++;
        }
    }

    cout << max(val, 1LL) << '\n';

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}