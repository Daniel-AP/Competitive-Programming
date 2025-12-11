#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    for(int i = 1; i < n; i++) {
        ans += max(a[i-1]-a[i], 0LL);
        a[i] = max(a[i-1], a[i]);
    }

    cout << ans << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}