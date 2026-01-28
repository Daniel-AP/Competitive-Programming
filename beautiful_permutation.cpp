#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int l, r;

    int lb = 1, rb = n, mid;

    while(lb <= rb) {

        mid = lb+(rb-lb)/2;

        int nomod, mod;

        cout << 1 << ' ' << 1 << ' ' << mid << endl;
        cin >> nomod;
        cout << 2 << ' ' << 1 << ' ' << mid << endl;
        cin >> mod;

        if(mod > nomod) {
            l = mid;
            rb = mid-1;
        } else {
            lb = mid+1;
        }

    }

    lb = l, rb = n;

    int diff;
    int nomod, mod;

    cout << 1 << ' ' << l << ' ' << n << endl;
    cin >> nomod;
    cout << 2 << ' ' << l << ' ' << n << endl;
    cin >> mod;

    diff = mod-nomod;

    cout << '!' << ' ' << l << ' ' << l+diff-1 << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}