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

    if(count(a.begin(), a.end(), a[0]) == n) {
        return void(cout << "NO" << '\n');
    }

    int j = -1;

    cout << "YES" << '\n';

    for(int i = 1; i < n; i++) {
        if(a[i] != a[0]) {
            cout << 1 << ' ' << i+1 << '\n';
            j = i;
        }
    }

    for(int i = 1; i < n; i++) {
        if(a[i] == a[0]) {
            cout << j+1 << ' ' << i+1 << '\n';
        }
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}