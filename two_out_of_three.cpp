#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n, 1);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, vector<int>> e;
    for(int i = 0; i < n; i++) {
        e[a[i]].push_back(i);
    }

    vector<int> _2;

    for(auto& [k, v]: e) {
        if(v.size() >= 2) _2.push_back(k);
    }

    if(_2.size() < 2) return void(cout << -1 << '\n');

    b[e[_2[0]][1]] = 2;
    b[e[_2[1]][1]] = 3;

    for(int x: b) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}