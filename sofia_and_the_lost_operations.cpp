#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n), c;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int m; cin >> m;
    vector<int> d(m);

    for(int i = 0; i < m; i++) cin >> d[i];

    map<int, int> mp1, mp2;

    for(int i = 0; i < m; i++) {
        mp1[d[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(b[i] != a[i]) {
            mp2[b[i]]++;
        }
    }

    for(auto [k, v]: mp2) {
        if(mp1[k] < v) return void(cout << "NO" << '\n');
    }

    if(find(b.begin(), b.end(), d.back()) != b.end()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}