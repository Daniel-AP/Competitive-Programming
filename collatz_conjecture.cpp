#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int x, y, k; cin >> x >> y >> k;
    
    while(1) {
        if(k == 0) return void(cout << x << '\n');
        if(x == 1) break;
        if(k >= (x+y)/y*y-x) {
            k -= (x+y)/y*y-x;
            x = (x+y)/y*y;
            while(x%y == 0) x /= y;
        } else {
            return void(cout << x+k << '\n');
        }
    }

    k %= y-1;

    cout << x+k << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}