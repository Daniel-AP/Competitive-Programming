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

    for(int i = 0; i+1 < n; i++) {
        if(s[i] == ')' && s[i+1] == '(') {
            int cnt = count(s.begin()+i+1, s.end(), '(')-1;
            if(cnt == 0) return void(cout << -1 << '\n');
            return void(cout << n-2 << '\n');
        }
    }

    cout << -1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}