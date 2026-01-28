#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    int ans = 0;
    for(const auto& [x, y] : freq) {
        int l = min(m / x, y);
        ans = max(ans, l*x);
        if(!freq.count(x+1)) continue;
        int z = freq[x+1];
        for(int i = 1; i <= y; i++) {
            if(i*x > m) break;
            int du = m-i*x;
            int su = min(du / (x+1), z)*(x+1)+i*x;
            ans = max(ans, su);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tests; cin >> tests;
    while(tests--) {
        solve();
    }
    return 0;
}
