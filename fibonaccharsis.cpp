#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, k; cin >> n >> k;
    int ans = 0;

    k--;

    if(k > 35) return void(cout << ans << '\n');

    for(int i = 0; i <= n; i++) {

        int l = i, r = n, mid;

        while(l <= r) {

            mid = l+(r-l)/2;

            vector<int> fib(35);
            fib[0] = i, fib[1] = mid;

            for(int j = 2; j < 35; j++) fib[j] = fib[j-1]+fib[j-2];

            if(fib[k] == n) {
                ans++;
                break;
            } else if(fib[k] < n) {
                l = mid+1;
            } else {
                r = mid-1;
            }

        }

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}