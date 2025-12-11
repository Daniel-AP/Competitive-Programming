#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> b(n), ans(n);
    map<int, vector<int>> mp;

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]].push_back(i);
    }
    
    for(auto [k, v]: mp) {
        if(v.size()%k != 0) return void(cout << -1 << '\n');
    }

    int cnt = 1;

    for(auto [k, v]: mp) {
        int i = 0;
        while(i < v.size()) {
            for(int j = i; j < k+i; j++) {
                ans[v[j]] = cnt;
            }
            i += k;
            cnt++;
        }
    }

    mp.clear();

    for(int i = 0; i < n; i++) {
        mp[ans[i]].push_back(i);
    }

    for(int i = 0; i < n; i++) {
        if(mp[ans[i]].size() != b[i] || ans[i] > n) return void(cout << -1 << '\n');
    }

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}