#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<pair<double, double>> pv(n);
    vector<array<double, 3>> res;

    for(int i = 0; i < n; i++) {
        double p, v; cin >> p >> v;
        pv[i] = { p, v };
    }

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);

    sort(ind.begin(), ind.end(), [&](int x, int y) {
        return pv[x] < pv[y];
    });

    for(int i = 0; i < n-1; i++) {

        double idx = ind[i], nxIdx = ind[i+1];
        double t = (pv[nxIdx].first-pv[idx].first)/(pv[idx].second-pv[nxIdx].second);

        if(t >= 0 && (pv[idx].second-pv[nxIdx].second) != 0) res.push_back({ t, idx, nxIdx });

    }

    sort(res.begin(), res.end(), [&](array<double, 3> t1, array<double, 3> t2) {
        
        auto [a1, b1, c1] = t1;
        auto [a2, b2, c2] = t2;

        if(a1 != a2) return a1 < a2;
        else return make_pair(b1, c1) < make_pair(b2, c2);
        
    });

    if(res.size() == 0) {
        cout << -1 << '\n';
    } else {
        auto [a, b, c] = res[0];
        cout << a << ' ' << (int)(b+1) << ' ' << (int)(c+1);
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}