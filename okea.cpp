#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, k; cin >> n >> k;

    if(k == 1 || (n*k/2)%k == 0 && ((n*k+1)/2)%k == 0) {
        cout << "YES" << '\n';
        for(int i = 1; i <= n*k; i += 2) {
            cout << i << ' ';
            if(((i-1)/2+1)%k == 0) cout << '\n';
        }
        for(int i = 2; i <= n*k; i += 2) {
            cout << i << ' ';
            if(i/2%k == 0) cout << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}