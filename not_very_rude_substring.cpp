#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, c; cin >> n >> c;
    string s; cin >> s;

    int cntA = 0, cntB = 0, cur = 0, l = 0, ans = 0;

    for(int r = 0; r < n; r++) {
        cntA += (s[r]=='a');
        cntB += (s[r]=='b');
        cur += (s[r]=='b')*cntA;
        while(cur > c) {
            cntA -= (s[l]=='a');
            cntB -= (s[l]=='b');
            cur -= (s[l]=='a')*cntB;
            l++;
        }
        ans = max(ans, r-l+1);
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