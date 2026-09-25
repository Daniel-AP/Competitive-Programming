#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> ones;
    int last_mone = -1;
    
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) ones.push_back(i);
        if(a[i] == -1) last_mone = i;
    }

    int best = 0, sw1 = -1, sw2 = -1;

    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            auto it = upper_bound(all(ones), i);
            if(it == ones.end()) {
                if(last_mone > i) {
                    if(best < (last_mone-i+1)) best = (last_mone-i+1), sw1 = last_mone, sw2 = -1;
                }
                continue;
            }
            int j = it-ones.begin();
            if(best < (ones[j]-i+1)) best = (ones[j]-i+1), sw1 = -1, sw2 = -1;
        } else if(a[i] == -1) {
            auto it = upper_bound(all(ones), i);
            if(it == ones.end()) {
                if(last_mone > i) {
                    if(best < (last_mone-i+1)) best = (last_mone-i+1), sw1 = i, sw2 = last_mone;
                }
                continue;
            }
            int j = it-ones.begin();
            if(best < (ones[j]-i+1)) best = (ones[j]-i+1), sw1 = i, sw2 = -1;
        }
    }

    if(ones.empty() && sw1 == -1 && last_mone != -1) sw1 = last_mone;

    if(sw1 != -1) a[sw1] = 1;
    if(sw2 != -1) a[sw2] = 1;

    for(int i = 0; i < n; i++) {
        if(a[i] == -1) cout << 0 << ' ';
        else cout << a[i] << ' ';
    }

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