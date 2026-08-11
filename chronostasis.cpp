#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    int sm = 0;
    for(int i = 0; i < n; i++) sm += b[i];

    vector<int> ind(n);
    iota(all(ind), 0);

    sort(all(ind), [&](int i, int j) { return b[i] < b[j]; });

    int a0 = -1, inda0 = -1;

    for(int i: ind) {
        if(b[i] <= 0) continue;
        if(b[i]+(sm-b[i]) > 0) {
            a0 = b[i];
            inda0 = i;
            break;
        }
    }

    if(a0 == -1) return void(cout << -1 << '\n');

    multiset<int> neg, pos;

    for(int i = 0; i < n; i++) {
        if(b[i] < 0) neg.insert(-b[i]);
        else if(i != inda0) pos.insert(b[i]);
    }

    int cur = a0;

    vector<int> ans(n);
    ans[0] = a0;

    for(int i = 1; i < n; i++) {
        int lb = cur-1;
        auto it = neg.upper_bound(lb);
        if(it == neg.begin()) {
            cur += *pos.begin();
            pos.erase(pos.begin());
        } else {
            it--;
            cur -= *it;
            neg.erase(it);
        }
        ans[i] = cur;
    }

    for(int x: ans) cout << x << ' ';
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