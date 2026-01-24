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

    vector<int> ind(n);
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j) { return a[i] > a[j]; });

    vector<int> color(n);
    for(int i = 1; i < n; i++) color[i] = 1-color[i-1];

    bool ok1 = true, ok2 = true;

    for(int i = 0; i+1 < n; i++) {
        if(color[ind[i]] == color[ind[i+1]]) ok1 = false;
    }

    color[0] = 1;
    for(int i = 1; i < n; i++) color[i] = 1-color[i-1];

    for(int i = 0; i+1 < n; i++) {
        if(color[ind[i]] == color[ind[i+1]]) ok2 = false;
    }

    cout << (ok1 || ok2 ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}