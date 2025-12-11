#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int a, b; cin >> a >> b;

    cout << 3 << '\n';
    
    int n1 = b, n2 = b, n3 = b;

    if(n1+n2+n3 < 3*a) n3 += (3*a-n1-n2-n3);
    if(n1+n2+n3 > 3*a) n1 -= (n1+n2+n3-3*a);

    cout << n1 << ' ' << n2 << ' ' << n3 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}