#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, m; cin >> n >> m;

    vector<string> mat(n);

    for(int i = 0; i < n; i++) cin >> mat[i];

    int sx = 0, sy = 0, ans = 0;

    while(min(n, m) > 0) {

        string layer;

        for(int i = sx; i < sx+m; i++) layer += (mat[sy][i]);
        for(int i = sy+1; i < sy+n-1; i++) layer += (mat[i][sx+m-1]);
        for(int i = sx+m-1; i > sx; i--) layer += (mat[sy+n-1][i]);
        for(int i = sy+n-1; i > sy; i--) layer += (mat[i][sx]);

        layer += layer.substr(0, 3);

        int pos = 0;

        while(layer.find("1543", pos) != layer.npos) {
            ans++;
            pos = layer.find("1543", pos)+1;
        }

        n -= 2; m -= 2;
        sx++; sy++;

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}