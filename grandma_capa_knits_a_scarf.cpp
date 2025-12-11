#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int ans = INF;

    for(int i = 0; i < 26; i++) {
        int l = 0, r = n-1, t = 0;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
                continue;
            }
            if(s[l] == char('a'+i)) {
                t++;
                l++;
            } else if(s[r] == char('a'+i)) {
                r--;
                t++;
            } else {
                t = INF;
                break;
            }
        }
        ans = min(ans, t);
    }

    cout << (ans == INF ? -1 : ans) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}