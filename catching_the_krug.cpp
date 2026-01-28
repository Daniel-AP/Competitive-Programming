#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, rk, ck, rd, cd; cin >> n >> rk >> ck >> rd >> cd;

    int distX = abs(ck-cd), distY = abs(rk-rd);
    int availableX = 0, availableY = 0;

    if(ck < cd) {
        availableX = ck;
    } else if(ck > cd) {
        availableX = n-ck;
    }

    if(rk < rd) {
        availableY = rk;
    } else if(rk > rd) {
        availableY = n-rk;
    }

    availableX += distX;
    availableY += distY;

    cout << max(availableX, availableY) << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}