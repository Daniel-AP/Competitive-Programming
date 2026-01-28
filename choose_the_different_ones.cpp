#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, m, k; cin >> n >> m >> k;

    set<int> a, b;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x <= k) a.insert(x);
    }

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        if(x <= k) b.insert(x);
    }
    
    for(int i = 1; i <= k; i++) {
        if(!a.count(i) && !b.count(i)) return void(cout << "NO" << '\n');
    }

    int cnta = 0, cntb = 0;

    for(int i = 1; i <= k; i++) {
        if(a.count(i) && !b.count(i)) cnta++;
        if(b.count(i) && !a.count(i)) cntb++;
    }

    for(int i = 1; i <= k; i++) {
        if(a.count(i) && b.count(i)) {
            if(cnta < cntb) cnta++;
            else cntb++;
        }
    }

    if(cnta == k/2 && cntb == k/2) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}