#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int l, r; cin >> l >> r;
    int L, R; cin >> L >> R;

    int a = max(min(r, R)-max(l, L)+1, 0LL);
    
    if(l < L && r > R) cout << a+1 << '\n';
    else if(L < l && R > r) cout << a+1 << '\n';
    else if(l == L && R == r) cout << a-1 << '\n';
    else cout << max(a+(a<min(r-l+1, R-L+1)), 1LL) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}