#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, q; cin >> n >> q;

    vector<int> x(n), prefix(n+1);
    for(int i = 0; i < n; i++) cin >> x[i];

    for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1]^x[i-1];

    while(q--) {

        int a, b; cin >> a >> b;
        cout << (prefix[b]^prefix[a-1]) << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}