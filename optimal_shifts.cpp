#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int mx = 0;
    int i1 = s.find('1'), i2 = s.rfind('1');

    for(int i = 0; i < i1; i++) mx++;
    for(int i = i2+1; i < n; i++) mx++;

    int cnt = 0;

    for(int i = i1; i <= i2; i++) {
        if(s[i] == '0') cnt++;
        else {
            mx = max(mx, cnt);
            cnt = 0;
        }
    }

    cout << mx << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}