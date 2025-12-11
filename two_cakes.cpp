#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n, a, b; cin >> n >> a >> b;

    int mx = -INF;

    for(int i = 1; i < n; i++) {
        mx = max(min(a/i, b/(n-i)), mx);
    }

    cout << mx << "\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}