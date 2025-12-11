#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];

    vector<pair<int, int>> lr(n);

    for(int i = 0; i < n; i++) {
        int li, ri; cin >> li >> ri;
        lr[i] = { li, ri };
    }

    vector<int> l(n), r(n);

    l[0] = lr[0].first;
    r[n-1] = lr[n-1].second;

    for(int i = 1; i < n; i++) l[i] = max(l[i-1], lr[i].first);
    for(int i = n-2; i >= 0; i--) r[i] = min(r[i+1], lr[i].second);

    vector<int> ans(n), can;
    for(int i = 0; i < n; i++) if(d[i] != -1) ans[i] = d[i];

    int curr = 0;

    for(int i = 0; i < n; i++) {

        curr += ans[i];

        if(d[i] == -1) can.push_back(i);
        if(curr > r[i] || l[i] > r[i]) return void(cout << -1 << '\n');

        if(curr < l[i]) {

            int need = l[i]-curr;

            if(need > can.size()) return void(cout << -1 << '\n');

            while(need--) ans[can.back()] = 1, curr++, can.pop_back();

        }

        if(i+1 < n && r[i] < r[i+1]) {
            while(can.size() > r[i]-curr) can.pop_back();
        }

    }

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}