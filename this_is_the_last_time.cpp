#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n, k; cin >> n >> k;

    vector<int> real(n), ind(n);
    vector<pair<int, int>> lr(n);

    for(int i = 0; i < n; i++) {

        int li, ri; cin >> li >> ri;

        lr[i] = { li, ri };
        cin >> real[i];

    }

    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int x, int y) {
        if(real[x] == real[y]) return lr[x].first < lr[y].first;
        return real[x] < real[y];
    });

    int ans = 0;
    int start = -1;

    for(int i = 0; i < n; i++) {
        if(k < lr[ind[i]].first || k > lr[ind[i]].second) continue;
        start = i;
        ans = max(ans, real[ind[i]]);
    }

    if(start == -1) {
        cout << k << '\n';
        return;
    }

    for(int i = start+1; i < n; i++) {
        if(ans < lr[ind[i]].first || ans > lr[ind[i]].second) continue;
        ans = max(ans, real[ind[i]]);
    }

    cout << max(ans, k) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}