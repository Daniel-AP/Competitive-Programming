#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b, c; cin >> a >> b >> c;

    if(a >= b) cout << a+c-b;
    else if(abs(a+c-b) >= abs(a-b)) cout << abs(a+c-b);
    else cout << abs(a-b);

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}