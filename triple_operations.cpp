#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

const int N = 200005;

vector<int> prefix(N+1);

void pre() {

    vector<int> a(N);

    for(int i = 1; i < N; i++) {
        int x = i;
        while(x) {
            a[i]++;
            x /= 3;
        }
    }

    partial_sum(a.begin()+1, a.end(), prefix.begin()+1);

}

void solve() {

    int l, r; cin >> l >> r;
    
    cout << prefix[r]-prefix[l-1]+prefix[l]-prefix[l-1] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}