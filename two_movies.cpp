#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int m1 = 0, m2 = 0, neg = 0, pos = 0;
    
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            if(a[i] == -1) neg++;
            if(a[i] == 1) pos++;
        } else {
            if(a[i] > b[i]) m1 += a[i];
            else m2 += b[i];
        }
    }

    int d = abs(m1-m2);

    if(m1 < m2) m1 += min(d, pos), pos -= min(d, pos);
    else m2 += min(d, pos), pos -= min(d, pos);
    
    m1 += pos/2, m2 += (pos+1)/2;

    d = abs(m1-m2);

    if(m1 > m2) m1 -= min(d, neg), neg -= min(d, neg);
    else m2 -= min(d, neg), neg -= min(d, neg);

    m1 -= neg/2, m2 -= (neg+1)/2;

    cout << min(m1, m2) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}