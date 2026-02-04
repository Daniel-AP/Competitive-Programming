#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, l, r; cin >> n >> k >> l >> r;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int lb = 0, ans = 0, un = 0;

    map<int, int> cnt, prev;
    set<int> last;

    auto add = [&](int rb) {
        if(cnt[a[rb]] == 0) un++;
        last.insert(rb);
        if(prev.find(a[rb]) != prev.end()) last.erase(prev[a[rb]]);
        prev[a[rb]] = rb;
        cnt[a[rb]]++;
    };

    auto remove = [&](int lb) {
        cnt[a[lb]]--;
        if(cnt[a[lb]] == 0) un--;
        if(*last.begin() == lb) {
            last.erase(last.begin());
            prev.erase(a[lb]);
        }
    };

    for(int rb = 0; rb < n; rb++) {
        add(rb);
        while(un > k || rb-lb+1 > r) remove(lb++);
        if(last.empty() || un != k) continue;
        int rr = min(rb-l+1, *last.begin());
        ans += max(rr-lb+1, 0LL);
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