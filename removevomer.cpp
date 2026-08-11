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

    int cnt0 = count(all(s), '0'), cnt1 = count(all(s), '1');
    int start0 = 0, start1 = 0;

    if(cnt0 == n || cnt1 == n) return void(cout << 1 << '\n');

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') break;
        start0++;
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') break;
        start1++;
    }

    if(start0 == cnt0 || start1 == cnt1) cout << 2 << '\n';
    else cout << 1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}