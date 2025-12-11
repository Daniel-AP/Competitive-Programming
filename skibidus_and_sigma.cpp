#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> S(n), K(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            S[i] += (m-j)*a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            K[i] += a[i][j];
        }
    }

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);

    sort(ind.begin(), ind.end(), [&](int i, int j) {
        return K[i] > K[j];
    });

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int k = i*m;
        for(int j = 0; j < m; j++) {
            ans += a[ind[i]][j]*(n*m-(k+j));
        }
    }

    cout << ans << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}