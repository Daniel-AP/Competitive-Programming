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

    int s = 0;

    for(int i = 0; i < n; i++) {
        if(i%2) s -= a[i];
        else s += a[i];
    }

    int maxNeg = -INF, minPos = INF, inc = n-2+n%2;

    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            inc = max(inc, maxNeg-(2*a[i]-i));
            minPos = min(minPos, i+2*a[i]);
        } else {
            inc = max(inc, (i+2*a[i])-minPos);
            maxNeg = max(maxNeg, 2*a[i]-i);
        }
    }

    cout << s+inc << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}