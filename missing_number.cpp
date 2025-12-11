#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;
    int ans = n;

    for(int i = 0; i < n-1; i++) {
        int x; cin >> x;
        ans ^= x^(i+1);
    }

    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}