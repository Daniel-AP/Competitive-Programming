#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(is_sorted(all(a))) return void(cout << -1 << '\n');

    vector<pair<int, int>> b(n);
    for(int i = 0; i < n; i++) b[i] = {a[i], i};

    sort(all(a));
    sort(all(b));

    int mn = b[0].first, mx = b[n-1].first;
    int l = 1, r = 1e9, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;

        bool bad = false;

        vector<bool> can1(n), can2(n);

        for(int i = 0; i < n; i++) {
            if(a[i]-mn >= mid) can1[b[i].second] = 1;
        }

        for(int i = 0; i < n; i++) {
            if(mx-a[i] >= mid) can2[b[i].second] = 1;
        }

        for(int i = 0; i < n; i++) {
            if(b[i].second == i) continue;
            if(!can1[i] && !can2[i]) bad = true;
        }

        if(!bad) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }

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