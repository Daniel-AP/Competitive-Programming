#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;

    while(i < n && j < m) {
        if(a[i] < b[j]) {
            cout << a[i] << ' ';
            i++;
        } else {
            cout << b[j] << ' ';
            j++;
        }
    }

    while(i < n) cout << a[i++] << ' ';
    while(j < m) cout << b[j++] << ' ';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}