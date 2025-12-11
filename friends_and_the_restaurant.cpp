#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    vector<int> y(n);
    for(int i = 0; i < n; i++) cin >> y[i];

    vector<int> neg, pos;

    for(int i = 0; i < n; i++) {
        if(y[i] >= x[i]) {
            pos.push_back(y[i]-x[i]);
        } else {
            neg.push_back(x[i]-y[i]);
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int ans = 0, m = 0, i = 0, j = 0;

    while(i < pos.size() && j < neg.size()) {
        if(pos[i] >= neg[j]) {
            ans++;
            i++;
            j++;
        } else {
            i++;
            m++;
        }
    }

    m += pos.size()-i;

    cout << ans+m/2 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}