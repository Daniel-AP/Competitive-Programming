#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> ind(n);
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j) { return a[i] < a[j]; });

    ordered_set<pair<int, int>> os;
    map<int, int> cnt;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int j = ind[i];
        if(i+1 < n && a[ind[i+1]] == a[j]) { os.insert({b[j], i}); cnt[a[j]]++; continue; }
        if(i-os.order_of_key({a[j], -1LL})-cnt[a[j]] > k) { os.insert({b[j], i}); cnt[a[j]]++; continue; }
        ans = max(ans, (int)(n-os.order_of_key({a[j], -1LL}))*a[j]);
        os.insert({b[j], i});
        cnt[a[j]]++;
    }

    os.clear();

    sort(all(ind), [&](int i, int j) { return b[i] < b[j]; });

    for(int i = n-1; i >= 0; i--) {
        int j = ind[i];
        if(i > 0 && b[ind[i-1]] == b[j]) { os.insert({a[j], j}); continue; }
        if(n-i-((n-i-1)-os.order_of_key({b[j], -1LL})) > k) { os.insert({a[j], j}); continue; }
        ans = max(ans, (n-i)*b[j]);
        os.insert({a[j], j});
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