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

    vector<int> first(m, INF), last(m, -INF);

    int j = 0;

    for(int i = 0; i < n && j < m; i++) {
        if(a[i] >= b[j]) {
            first[j] = i;
            j++;
        }
    }

    if(j == m) return void(cout << 0 << '\n');
    if(m == 1) return void(cout << b[0] << '\n');
    
    j = m-1;

    for(int i = n-1; i >= 0 && j >= 0; i--) {
        if(a[i] >= b[j]) {
            last[j] = i;
            j--;
        }
    }

    int ans = INF;

    if(last[1] != -INF) ans = min(ans, b[0]);

    for(int i = 1; i+1 < m; i++) {
        if(first[i-1] < last[i+1]) {
            ans = min(ans, b[i]);
        }
    }

    if(first[m-2] != INF) ans = min(ans, b[m-1]);

    cout << (ans == INF ? -1 : ans) << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}