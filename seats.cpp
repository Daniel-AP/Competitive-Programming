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

    if(count(all(s), '0') == n) return void(cout << (n+2)/3 << '\n');

    int cur = 0, tot = 0;
    int i = (s.find('1') != string::npos ? s.find('1') : 0);

    if(i > 1) tot += (i+1)/3;

    for(; i < n; i++) {
        if(s[i] == '0') {
            cur++;
        } else {
            tot++;
            tot += cur/3;
            cur = 0;
        }
    }

    if(cur > 1) tot += (cur+1)/3;

    cout << tot << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}