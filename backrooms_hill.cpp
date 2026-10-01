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

    vector<int> pos(n+1);

    for(int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }

    if(n%2) {
        for(int i = 2; i+1 <= n; i += 2) {
            if(pos[i]%2 == pos[i+1]%2) return void(cout << "NO" << '\n');
        }
    } else {
        for(int i = 1; i+1 <= n; i += 2) {
            if(pos[i]%2 == pos[i+1]%2) return void(cout << "NO" << '\n');
        }
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