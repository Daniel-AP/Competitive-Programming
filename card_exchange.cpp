#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k; cin >> n >> k;

        vector<int> c(n);
        for(int i = 0; i < n; i++) cin >> c[i];

        set<int> s(c.begin(), c.end());
        vector<int> cnt(n);

        for(int m: s) {
            int p = count(c.begin(), c.end(), m);
            cnt.push_back(p);
        }

        sort(cnt.begin(), cnt.end());

        int ans = n;

        while(cnt[cnt.size()-1] >= k) {
            cnt[cnt.size()-1] -= k;
            sort(cnt.begin(), cnt.end());
            cnt[cnt.size()-1] += k-1;
            ans--;
        }

        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}