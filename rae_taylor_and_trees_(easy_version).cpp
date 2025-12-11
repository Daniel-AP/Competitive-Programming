#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {

    int n; cin >> n;

    vector<int> p(n), pp;

    for(int i = 0; i < n; i++) cin >> p[i];
    pp = p;

    int mn = pp[0];
    vector<int> mxs, mns;

    for(int i = 1; i < n; i++) {
        if(pp[i] < mn) {
            mn = pp[i];
        } else {
            pp[i] = mn;
        }
    }
    
    int mx = p[0];

    for(int i = 1; i < n; i++) {
        if(pp[i] != pp[i-1]) {
            mns.push_back(pp[i-1]);
            mxs.push_back(mx);
            mx = p[i];
        } else {
            mx = max(mx, p[i]);
        }
    }

    mns.push_back(pp[n-1]);
    mxs.push_back(mx);

    vector<int> mxx(mxs.size());
    mxx[mxx.size()-1] = mxs.back();
    for(int i = mxx.size()-2; i >= 0; i--) mxx[i] = max(mxs[i+1], mxx[i+1]);

    for(int i = 0; i+1 < mxs.size(); i++) {
        if(mns[i] > mxx[i]) return void(cout << "No" << '\n');
    }

    cout << "Yes" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}