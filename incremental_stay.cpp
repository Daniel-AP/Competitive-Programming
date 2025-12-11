#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(2*n);
    for(int i = 0; i < 2*n; i++) cin >> a[i];

    int sl = 0, sr = 0, smid = 0;
    for(int i = 0; i < 2*n; i++) {
        if(i&1) smid -= a[i];
        else smid += a[i];
    }

    int l = 0, r = 2*n-1;

    while(l < r) {
        sl += a[l], sr += a[r];
        smid *= -1;
        smid += a[l], smid -= a[r];
        l++, r--;
        cout << sr-sl+smid << ' ';
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