#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();

    int a = INF, b = INF;

    vector<int> close(n);

    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'a') a = min(a, i), close[i] = b;
        if(s[i] == 'b') b = min(b, i), close[i] = a;
    
    }

    vector<int> ways(n), sx(n);
    sx[n-1] = ways[n-1] = (s[n-1] == 'a');

    for(int i = n-2; i >= 0; i--) {
        ways[i] = (s[i] == 'a');
        if(s[i] == 'a' && close[i] != INF) {
            ways[i] += sx[close[i]];
        }
        sx[i] = (sx[i+1]+ways[i])%MOD;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans += ways[i];
        ans %= MOD;
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