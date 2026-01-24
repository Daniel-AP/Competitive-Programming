#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int nb, ns, nc; cin >> nb >> ns >> nc;
    int pb, ps, pc; cin >> pb >> ps >> pc;
    int r; cin >> r;

    int lb = 0, rb = 1e14, mid, ans;

    int cntB = count(all(s), 'B');
    int cntS = count(all(s), 'S');
    int cntC = count(all(s), 'C');

    while(lb <= rb) {

        mid = lb+(rb-lb)/2;

        int needB = max(mid*cntB-nb, 0LL);
        int needS = max(mid*cntS-ns, 0LL);
        int needC = max(mid*cntC-nc, 0LL);

        if(needB*pb+needS*ps+needC*pc <= r) {
            ans = mid;
            lb = mid+1;
        } else {
            rb = mid-1;
        }

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}