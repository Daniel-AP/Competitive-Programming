#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    if(k == 1) {

        int mn = a[0];
        
        for(int i = 0; i+1 < n; i++) {
            mn = min(mn, abs(a[i]-a[i+1]));
        }

        return void(cout << mn << '\n');

    }

    if(k == 2) {

        int mn = a[0];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int val = abs(a[i]-a[j]);
                mn = min(mn, val);
                auto it1 = upper_bound(a.begin(), a.end(), val)-1;
                auto it2 = upper_bound(a.begin(), a.end(), val);
                if(it1 != a.end() && it2 != a.end()) {
                    mn = min({ mn, abs(*it1-val), abs(*it2-val) });
                } else if(it1 != a.end()) {
                    mn = min(mn, abs(*it1-val));
                }
            }
        }

        return void(cout << mn << '\n');

    }
 
    cout << 0 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}