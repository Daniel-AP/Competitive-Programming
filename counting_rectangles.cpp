#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000;

void solve() {

    int n, q; cin >> n >> q;

    vector<vector<int>> cnt(N+1, vector<int>(N+1));

    for(int i = 0; i < n; i++) {
        int h, w; cin >> h >> w;
        cnt[h][w] += h*w;
    }

    vector<vector<int>> px(N+1, vector<int>(N+1));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            px[i][j] = cnt[i][j]+px[i-1][j]+px[i][j-1]-px[i-1][j-1];
        }
    }

    while(q--) {

        int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;

        int uli = hs+1, ulj = ws+1, lri = hb-1, lrj = wb-1;
        cout << px[lri][lrj]-px[lri][ulj-1]-px[uli-1][lrj]+px[uli-1][ulj-1] << '\n';

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