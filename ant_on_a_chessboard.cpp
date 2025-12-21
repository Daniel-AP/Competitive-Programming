#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve(int n) {

    int cur = 1, ans;

    while(cur*cur <= n) cur++;
    if((cur-1)*(cur-1) == n) cur--;

    if(cur%2) {
        ans = 1;
        ans += cur*cur-n;
    } else {
        ans = 2*cur-1;
        ans -= cur*cur-n;
    }

    cout << min(ans, cur) << ' ' << cur-max(ans-cur, 0LL) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(1) {
        int n; cin >> n;
        if(n == 0) break;
        solve(n);
    }

    return 0;

}