#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string t; cin >> t;

    int i = 0;
    string s;
    
    while(i < n) {
        if(i+2 < n && t[i+2] == '0' && (i+3 >= n || t[i+3] != '0')) {
            s += ((t[i]-'0')*10+(t[i+1]-'0'))+'a'-1;
            i += 3;
        } else {
            s += (t[i]-'0')+'a'-1;
            i++;
        }
    }

    cout << s << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}