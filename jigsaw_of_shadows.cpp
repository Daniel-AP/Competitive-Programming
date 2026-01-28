#include <bits/stdc++.h>
using namespace std;

#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    double theta; cin >> theta;
    int n; cin >> n;

    theta = theta*(acos(-1.0)/180.0);
    double t = cos(theta)/sin(theta);

    vector<pair<int, double>> sha(300005);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        double h; cin >> h;
        double l = h*t;
        sha[x] = { x, x+l };
    }

    double l = 0, r = 0, ans = 0;

    for(int i = 0; i < 300005; i++) {
        if(sha[i].first <= r) {
            r = max(r, sha[i].second);
        } else {
            ans += r-l;
            l = sha[i].first, r = sha[i].second;
        }
    }

    ans += r-l;

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}