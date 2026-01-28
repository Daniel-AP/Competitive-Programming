#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, c; cin >> n >> c;

    multiset<int, greater<int>> a;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(*a.rbegin() > c) break;
        for(int x: a) {
            if(x <= c) {
                a.erase(a.find(x));
                break;
            }
        }
        multiset<int, greater<int>> b;
        for(int x: a) b.insert(2*x);
        a = b;
    }

    ans += a.size();

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}