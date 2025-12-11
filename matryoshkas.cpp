#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int ans = cnt[a[0]];

    for(int i = 1; i < n; i++) {
        if(a[i] <= a[i-1]+1) {
            if(cnt[a[i]] > cnt[a[i-1]]) {
                ans += cnt[a[i]]-cnt[a[i-1]];
            }
        } else {
            ans += cnt[a[i]];
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}