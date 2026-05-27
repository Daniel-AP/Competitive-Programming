#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();

    vector<int> px4(n+1);
    
    for(int i = 1; i <= n; i++) {
        px4[i] = px4[i-1]+(s[i-1]=='4');
        if(s[i-1]=='4') s[i-1] = '#';
    }

    vector<int> px2(n+1);

    for(int i = 1; i <= n; i++) {
        px2[i] = px2[i-1]+(s[i-1]=='2');
    }

    int ans = px4[n]+px2[n];

    for(int i = 1; i <= n; i++) {
        ans = min(ans, i-px2[i]-px4[i]+(px2[n]-px2[i])+px4[n]);
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