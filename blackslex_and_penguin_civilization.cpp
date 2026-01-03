#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int cur = (1LL<<n)-1, cnt = 1;

    cout << cur << ' ';

    vector<int> has((1LL<<n));
    has[cur] = 1;

    while(cnt < (1LL<<n)) {
        for(int i = 0; i <= (1LL<<n)-1; i++) {
            if(has[i]) continue;
            if((cur&i) < cur) continue;
            has[i] = 1;
            cnt++;
            cout << i << ' ';
        }
        if(cur == 0) break;
        cur ^= bit_floor(cur);
        cout << cur << ' ';
        has[cur] = 1;
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}