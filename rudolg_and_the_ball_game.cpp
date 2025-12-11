#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, x; cin >> n >> m >> x;

    set<int> has1 = { x };

    while(m--) {

        int r; cin >> r;
        char c; cin >> c;

        set<int> has2;

        for(int p: has1) {
            if(c == '0') {
                has2.insert((p+r)%n);
            } else if(c == '1') {
                has2.insert((((p-r)%n)+n)%n);
            } else {
                has2.insert((p+r)%n);
                has2.insert((((p-r)%n)+n)%n);
            }
        }

        has1 = has2;

    }

    cout << has1.size() << '\n';

    if(has1.find(0) != has1.end()) {
        has1.erase(0);
        has1.insert(n);
    }

    for(int p: has1) {
        cout << p << ' ';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}