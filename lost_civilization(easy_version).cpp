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

    set<int> s;

    s.insert(a[0]);
    int ans = 1;

    for(int i = 1; i < n; i++) {
        if(a[i] <= *s.begin()) {
            s.clear();
            s.insert(a[i]);
            ans++;
            continue;
        }
        if(a[i] > a[i-1]+1) {
            s.clear();
            s.insert(a[i]);
            ans++;
            continue;
        }
        s.insert(a[i]);
        int mn = *s.begin(), mx = *s.rbegin();
        if(mx-mn+1 != s.size()) {
            s.clear();
            s.insert(a[i]);
            ans++;
        }
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