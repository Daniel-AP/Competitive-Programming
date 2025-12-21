#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int cnt2 = 0, cnt5 = 0;

    int cur = 2;

    while(cur <= n) {
        cnt2 += n/cur;
        cur *= 2;
    }

    cur = 5;

    while(cur <= n) {
        cnt5 += n/cur;
        cur *= 5;
    }

    cout << min(cnt2, cnt5) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}