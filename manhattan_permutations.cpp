#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    int mx = 0, cur = n-1;
    while(cur > 0) mx += cur*2, cur -= 2;

    if(k%2 || k > mx) return void(cout << "NO" << '\n');

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);

    for(int i = 0; i < n/2; i++) {
        int m = min(n-1-2*i, k/2);
        swap(ans[i], ans[i+m]);
        k -= m*2;
    }

    cout << "YES" << '\n';
    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}