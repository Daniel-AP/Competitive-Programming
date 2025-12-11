#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<vector<int>> a(3, vector<int>(n));
    vector<int> inda(n), indb(n), indc(n);

    iota(inda.begin(), inda.end(), 0);
    iota(indb.begin(), indb.end(), 0);
    iota(indc.begin(), indc.end(), 0);

    for(int i = 0; i < n; i++) cin >> a[0][i];
    for(int i = 0; i < n; i++) cin >> a[1][i];
    for(int i = 0; i < n; i++) cin >> a[2][i];

    sort(inda.begin(), inda.end(), [&](int i, int j) { return a[0][i] > a[0][j]; });
    sort(indb.begin(), indb.end(), [&](int i, int j) { return a[1][i] > a[1][j]; });
    sort(indc.begin(), indc.end(), [&](int i, int j) { return a[2][i] > a[2][j]; });

    vector<vector<int>> ind = { inda, indb, indc };

    int p[] = {0, 1, 2};
    int ans = 0;

    do {

        set<int> s;
        int t = 0;

        for(int i: p) {
            for(int j: ind[i]) {
                if(s.find(j) == s.end()) {
                    s.insert(j);
                    t += a[i][j];
                    break;
                }
            }
        }

        ans = max(ans, t);

    } while(next_permutation(p, p+3));

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}