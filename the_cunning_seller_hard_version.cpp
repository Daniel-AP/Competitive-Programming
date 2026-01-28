#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, k; cin >> n >> k;
    int c = 0;

    int f = 1, lg = 1;
    while(f*3 <= n) f *= 3, lg++;

    vector<int> a(lg), csts(lg);

    for(int i = 0, f = 1; i < lg; i++, f *= 3) {
        csts[i] = f*3+i*f/3;
    }

    // for(int x: csts) cout << x << ' ';
    // cout << "*****" << '\n';
 
    while(n > 0) {

        int p = 1, cnt = 0;
        while(p*3 <= n) p *= 3, cnt++;

        c += csts[cnt];
        k--;
        n -= p;
        a[cnt]++;

    }

    if(k < 0) return void(cout << -1 << '\n');

    for(int i = lg-1; i > 0; i--) {
        int dls = min(k/2, a[i]);
        a[i] -= dls;
        a[i-1] += dls*3;
        c -= csts[i]*dls;
        c += csts[i-1]*dls*3;
        k -= dls*2;
    }

    cout << c << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}