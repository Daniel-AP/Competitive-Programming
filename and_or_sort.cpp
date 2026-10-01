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

    if(s[0] == '1') return void(cout << count(all(s), '0') << '\n');

    int ans = INF;

    vector<int> px0(n+1), px1(n+1);

    for(int i = 1; i <= n; i++) px0[i] = px0[i-1]+(s[i-1]=='0');
    for(int i = 1; i <= n; i++) px1[i] = px1[i-1]+(s[i-1]=='1');

    for(int i = 1; i <= n; i++) {
        ans = min(ans, px1[i]+(px0[n]-px0[i]));
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