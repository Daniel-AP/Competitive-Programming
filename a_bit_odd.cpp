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

    int l = 0, r = n-1;

    while(l < n && s[l] == '0') l++;
    while(r >= 0 && s[r] == '1') r--;

    if(l == n || r == -1) return void(cout << "Bob" << '\n');

    string t = s.substr(l, r-l+1);
    int m = t.length();

    int cnt = 0, o = 0;

    for(char ch: t) {
        if(ch == '1') o++;
        else cnt += o;
    }

    if(cnt%2) return void(cout << "Alice" << '\n');
    if(n == 2) return void(cout << "Bob" << '\n');

    o = 0;
    vector<int> cntt(m);

    int z = 0;
    for(int i = m-1; i >= 0; i--) {
        if(t[i] == '0') z++;
        else cntt[i] = z;
    }

    for(int i = 0; i < m; i++) {
        if(t[i] == '1') {
            if(cntt[i]%2) return void(cout << "Alice" << '\n');
            o++;
        } else {
            if(o%2) return void(cout << "Alice" << '\n');
        }
    }

    cout << "Bob" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}