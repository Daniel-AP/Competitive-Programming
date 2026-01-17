#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) if(a[i]%2) a[i] += a[i]%10;

    sort(all(a));

    if(a[0] == a[n-1]) return void(cout << "YES" << '\n');

    for(int i = 0; i < n; i++) {
        if(a[i]%10 == 0) return void(cout << "NO" << '\n');
    }

    for(int i = 0; i < n; i++) {
        if(a[i]%10 == 2) {
            a[i] += 2+4;
        } else if(a[i]%10 == 4) {
            a[i] += 4;
        } else if(a[i]%10 == 6) {
            a[i] += 6+2+4;
        }
    }

    sort(all(a));

    for(int i = 0; i+1 < n; i++) {
        int m = (a[i+1]-a[i])%20;
        if(m != 0 && m != 8 && m != 14 && m != 16) return void(cout << "NO" << '\n');
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}