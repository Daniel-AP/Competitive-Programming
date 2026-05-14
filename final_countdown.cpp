#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    vector<int> d(n+1);

    for(int i = 1; i <= n; i++) {
        d[i] = d[i-1]+(s[i-1]-'0');
    }

    string ans;

    for(int i = n; i >= 1; i--) {
        ans += '0'+d[i]%10;
        d[i-1] += d[i]/10;
    }

    if(d[0] > 0) ans += to_string(d[0]);

    reverse(all(ans));

    int i = 0;
    while(ans[i] == '0') i++;

    for(; i < ans.size(); i++) cout << ans[i];
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