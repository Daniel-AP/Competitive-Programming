#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> b(n);
    for(int i = 0; i < n; i++) b[i] = { a[i], i+1 };

    sort(b.begin(), b.end());

    ordered_set<int> s;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(b[i].first < b[i].second) {
            ans += s.order_of_key(b[i].first);
            s.insert(b[i].second);
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