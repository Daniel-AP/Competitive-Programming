#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    map<int, vector<int>> a;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x].push_back(i+1);
    }

    map<int, int> mp;
    
    for(auto& [k, v]: a) {

        int l = 1, r = n, mid, ans = n;

        while(l <= r) {

            mid = l+(r-l)/2;
            vector<pair<int, int>> b;

            for(int i: v) b.push_back({ i, min(i+mid-1, n) });

            bool ok = (b[0].first <= mid && mid <= b[0].second);
            int prev = b[0].first;

            for(auto [l, r]: b) {
                ok &= (l-prev <= 1);
                prev = max(prev, r);
            }

            ok &= (b.back().second == n);

            if(ok) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }

        }

        if(mp.find(ans) == mp.end()) mp[ans] = k;
        else mp[ans] = min(mp[ans], k);

    }

    int mn = INF;

    for(int i = 1; i <= n; i++) {
        if(mp.find(i) != mp.end()) mn = min(mn, mp[i]);
        cout << (mn == INF ? -1 : mn) << ' ';
    }

    cout << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}