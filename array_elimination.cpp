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

    vector<int> cnt(32);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 32; j++) {
            if((a[i]&(1LL<<j))) {
                cnt[j]++;
            }
        }
    }

    int g = 0;
    for(int i = 0; i < 32; i++) g = gcd(g, cnt[i]);

    set<int> divs;

    for(int i = 1; i*i <= g; i++) {
        if(g%i == 0) {
            divs.insert(i);
            divs.insert(g/i);
        }
    }

    if(g == 0) {
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
    } else {
        for(int x: divs) cout << x << ' ';
        cout << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}