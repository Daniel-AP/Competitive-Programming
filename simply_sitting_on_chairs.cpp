#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int ans = 1;
    ordered_set<int> os;
    if(p[0] > 1) os.insert(p[0]);

    for(int i = 1; i < n; i++) {
        ans = max(ans, (int)(i-os.order_of_key(i+1)));
        if(p[i] > i+1) os.insert(p[i]);
    }

    ans = max(ans, (int)(n-os.size()));

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