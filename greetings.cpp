#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)


// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<array<int, 2>> ab(n);

    for(int i = 0; i < n; i++) cin >> ab[i][0] >> ab[i][1];

    sort(all(ab));

    ordered_set<int> os;

    int ans = 0;

    for(int i = n-1; i >= 0; i--) {
        ans += os.order_of_key(ab[i][1]);
        os.insert(ab[i][1]);
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