#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "\nTime elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    multiset<int, greater<int>> a, b;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        b.insert(x);
    }

    int turn = 0;

    while(!a.empty() && !b.empty()) {
        if(turn%2) {
            if(*b.begin() >= *a.begin()) a.erase(a.begin());
            else {
                int y = *a.begin();
                a.erase(a.begin());
                a.insert(y-*b.begin());
            }
        } else {
            if(*a.begin() >= *b.begin()) b.erase(b.begin());
            else {
                int y = *b.begin();
                b.erase(b.begin());
                b.insert(y-*a.begin());
            }
        }
        turn++;
    }

    if(a.empty()) cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    // START_TIMER;

    while(t--) solve();

    // END_TIMER;

    return 0;

}