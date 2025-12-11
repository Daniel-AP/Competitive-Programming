#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();

    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) {
            for(char j = 'a'; j <= 'z'; j++) {
                if(j != s[i-1]) {
                    if(i+1 < n && s[i+1] == j) continue;
                    s[i] = j;
                    break;
                }
            }
        }
    }

    cout << s << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}