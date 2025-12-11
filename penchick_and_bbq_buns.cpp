#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    if(n%2 == 1 && n < 26) {
        cout << -1 << '\n';
        return;
    }

    if(n%2 == 0) {
        for(int i = 1; i <= n/2; i++) cout << i << ' ' << i << ' ';
    } else {

        cout << 2 << ' ' << 1 << ' ' << 3 << ' ' << 3 << ' ' << 2 << ' ';
        cout << 4 << ' ' << 4 << ' ' << 5 << ' ' << 5 << ' ' << 6 << ' ';
        cout << 1 << ' ' << 7 << ' ' << 7 << ' ' << 6 << ' ';
        for(int i = 8; i <= 13; i++) cout << i << ' ' << i << ' ';
        cout << 1 << ' ';
        for(int i = 14; i < 14+(n-27)/2; i++) cout << i << ' ' << i << ' ';

    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}