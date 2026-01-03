#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();

    int cnt0 = count(all(s), '0'), cnt1 = count(all(s), '1');
    int ans = n;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            if(cnt1 == 0) {
                ans = i;
                break;
            }
            cnt1--;
        } else {
            if(cnt0 == 0) {
                ans = i;
                break;
            }
            cnt0--;
        }
    }

    cout << n-ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}