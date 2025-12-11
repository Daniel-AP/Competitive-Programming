#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, k; cin >> n >> k;

    vector<int> buck(n+1);
    map<int, int> freq;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    int cnt = 0;

    for(auto [x, y]: freq) {
        buck[y]++;
    }

    for(int i = 1; i <= n; i++) {
        cnt += min(k/i, buck[i]);
        k -= min(k/i, buck[i])*i;
    }

    int res = freq.size()-cnt;

    cout << max(res, 1LL) << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}