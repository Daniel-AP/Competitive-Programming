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

    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);

    int l = 0, r = n-1;

    while(true) {
        if(!s.empty() && l < n && r >= 0 && (a[l] == *s.begin() || a[l] == *s.rbegin())) {
            if(a[l] == *s.begin()) s.erase(*s.begin());
            else if(a[l] == *s.rbegin()) s.erase(*s.rbegin());
            l++;
        } else if(!s.empty() && l < n && r >= 0 && (a[r] == *s.begin() || a[r] == *s.rbegin())) {
            if(a[r] == *s.begin()) s.erase(*s.begin());
            else if(a[r] == *s.rbegin()) s.erase(*s.rbegin());
            r--;
        } else {
            break;
        }
    }

    if(l > r) cout << -1 << '\n';
    else cout << l+1 <<  ' ' << r+1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}