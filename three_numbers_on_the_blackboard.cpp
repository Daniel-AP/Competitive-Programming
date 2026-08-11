#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    array<int, 3> a{};
    for(int i = 0; i < 3; i++) cin >> a[i];

    sort(all(a));

    int ans = a.back()-a[0];

    a[2] = a[0]+a[1];
    sort(all(a));
    ans = min(ans, a.back()-a[0]);

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