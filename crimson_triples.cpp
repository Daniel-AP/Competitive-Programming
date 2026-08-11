#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int ans = 0;

    vector<int> divs(n+1);

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            divs[i]++;
        }
    }

    for(int b = 1; b <= n; b++) {
        ans += (n/b)*(n/b);
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