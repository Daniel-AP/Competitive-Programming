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
    int m = n-k+1;

    vector<int> a(k), b(k-1);

    for(int i = 0; i < k; i++) cin >> a[i];
    for(int i = 0; i+1 < k; i++) b[i] = a[i+1]-a[i];

    if(k == 1) return void(cout << "YES" << '\n');

    if(!is_sorted(b.begin(), b.end())) return void(cout << "NO" << '\n');
    if((a[1]-a[0])*m < a[0]) return void(cout << "NO" << '\n');

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}