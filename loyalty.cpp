#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;
    int s = 0;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans;

    sort(a.begin(), a.end());

    int l = 0, r = n-1, bonus = 0;

    while(l < r) {
        if((s+a[l])/x == s/x) {
            ans.push_back(a[l]);
            s += a[l];
            l++;
        } else {
            ans.push_back(a[r]);
            if((s+a[r])/x > s/x) bonus += a[r];
            s += a[r];
            r--;
        }
    }

    if(l == r) {
        ans.push_back(a[l]);
        if((s+a[l])/x > s/x) bonus += a[l];
    }

    cout << bonus << '\n';
    for(int k: ans) cout << k << ' ';
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