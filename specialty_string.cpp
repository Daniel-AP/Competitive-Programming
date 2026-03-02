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

    for(int j = 1; j < n; j++) {
        int cnt = 0;
        for(int k = 1; k < j; k++) if(s[k] == '*') cnt++;
        for(int i = 0; i < n; i++) {
            if(i+j < n && s[i] == s[i+j] && s[i] != '*' && (cnt == j-1 || j == 1)) {
                s[i] = '*', s[i+j] = '*';
            }
            if(i+1 < n && s[i+1] == '*') cnt--;
            if(i+j < n && s[i+j] == '*') cnt++;
        }
    }

    int cnt = count(all(s), '*');

    cout << (cnt == n ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}