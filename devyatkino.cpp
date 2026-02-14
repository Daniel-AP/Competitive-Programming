#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int k = 1, ans = INF;

    string s = to_string(n);

    if(s.find('7') != string::npos) ans = 0;

    while(n/k > 0) {
        for(int i = 0; i < 9; i++) {
            int m = n;
            m += k*10*(i+1)-i-1;
            s = to_string(m);
            if(s.find('7') != string::npos) ans = min(ans, i+1);
        }
        k *= 10;
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