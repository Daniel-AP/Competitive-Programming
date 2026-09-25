#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int x, y; cin >> x >> y;
    int a =  x&(x+y);

    for(int i = 0; i < 32; i++) {
        if(((x+y)&(1LL<<i)) == 0) continue;
        if(a+(1LL<<i) <= x && (a&(1ULL<<i)) == 0) a += (1ULL<<i);
    }

    cout << x+y << ' ' << x-a << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}