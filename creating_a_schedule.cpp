#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int l = 0, r = m-1;

    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < 6; j++) {
            if(j%2) cout << a[r] << ' ';
            else cout << a[l] << ' ';
        }
        cout << '\n';
        for(int j = 0; j < 6; j++) {
            if(j%2 == 0) cout << a[r] << ' ';
            else cout << a[l] << ' ';
        }
        l++, r--;
        cout << '\n';
    }

    if(n%2) {
        for(int j = 0; j < 6; j++) {
            if(j%2) cout << a[r] << ' ';
            else cout << a[l] << ' ';
        }
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