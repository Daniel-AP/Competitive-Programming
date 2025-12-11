#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int k, n; cin >> k >> n;

    vector<int> a(k);
    int s = 0;

    for(int i = 1; i < k; i++) {
        a[i]++;
        s++;
        if(s+k > n) return void(cout << '*' << '\n');
    }

    for(int i = 0; i < k; i++) {
        if(s+k+1 <= n) a[i]++, s++;
    }

    if(n-s-k > 1) cout << '*' << '\n';
    else {
        for(int i = 0; i < k; i++) {
            cout << string(a[i], '-') << 'X';
        }
        cout << string(n-s-k, '-') << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}