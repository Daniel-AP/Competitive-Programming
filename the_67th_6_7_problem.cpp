#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    array<int, 7> a{};
    for(int i = 0; i < 7; i++) cin >> a[i];

    int ans = -INF;
    int s = 0;

    for(int i = 0; i < 7; i++) s += a[i];

    for(int i = 0; i < 7; i++) {
        int ss = s;
        ss -= a[i];
        ans = max(ans, a[i]-ss);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}