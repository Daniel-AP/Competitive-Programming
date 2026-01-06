#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string a, b; cin >> a >> b;
    char has1, has2;

    if(a.find('S') != a.npos) has1 = 'S';
    if(a.find('M') != a.npos) has1 = 'M';
    if(a.find('L') != a.npos) has1 = 'L';

    if(b.find('S') != b.npos) has2 = 'S';
    if(b.find('M') != b.npos) has2 = 'M';
    if(b.find('L') != b.npos) has2 = 'L';

    if(has1 == has2) {
        int cnt1 = count(all(a), 'X'), cnt2 = count(all(b), 'X');
        if(cnt1 == cnt2) return void(cout << '=' << '\n');
        if(has1 == 'S') {
            if(cnt1 > cnt2) cout << '<' << '\n';
            else cout << '>' << '\n';
        } else {
            if(cnt1 > cnt2) cout << '>' << '\n';
            else cout << '<' << '\n';
        }
    } else {
        if(has1 > has2) cout << '<' << '\n';
        else cout << '>' << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}