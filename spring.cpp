#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b, c, m; cin >> a >> b >> c >> m;
    int abc = m/lcm(lcm(a, b), c);
    int ab = m/lcm(a, b)-abc;
    int ac = m/lcm(a, c)-abc;
    int bc = m/lcm(b, c)-abc;
    int A = m/a-ab-ac-abc;
    int B = m/b-ab-bc-abc;
    int C = m/c-ac-bc-abc;

    cout << A*6+(ab+ac)*3+2*abc << ' ' << B*6+(ab+bc)*3+2*abc << ' ' << C*6+(ac+bc)*3+2*abc << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}