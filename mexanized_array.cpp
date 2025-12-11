#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, k, x; cin >> n >> k >> x;

    if(k > n) return void(cout << -1 << '\n');
    if(k-1 > x) return void(cout << -1 << '\n');

    int s = 0;

    for(int i = 0; i < k; i++) s += i;

    if(k != x) s += x*(n-k);
    else s += (x-1)*(n-k);

    cout << s << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}