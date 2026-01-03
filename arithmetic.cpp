#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int fromBase(string n, int b) {

    if(b == 1) {
        int cnt = count(n.begin(), n.end(), '1');
        return cnt == n.length() ? cnt : -1;
    }

    int ans = 0;

    for(char d: n) {
        
        int val = 0;

        if('0' <= d && d <= '9') val = d-'0';
        else val = d-'A'+10;

        ans *= b;
        ans += val;

        if(val >= b) return -1;

    }

    return ans;

}

void solve() {

    string a, b, c, _;

    cin >> a >> _ >> b >> _ >> c;

    int ans = 0;

    for(int i = 1; i <= 36; i++) {
        int abi = fromBase(a, i), bbi = fromBase(b, i), cbi = fromBase(c, i);
        if(abi == -1 || bbi == -1 || cbi == -1) continue;
        if(abi+bbi != cbi) continue;
        ans = i;
        break;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}