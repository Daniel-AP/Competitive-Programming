#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, r, c; cin >> n >> k >> r >> c;

    vector<string> ans(n);
    string row(n, '.');

    for(int i = 0; i < n; i += k) row[i] = 'X';
    while(row[c-1] != 'X') rotate(row.rbegin(), row.rbegin()+1, row.rend());
    
    string cur = row;

    for(int i = r-1; i >= 0; i--) {
        ans[i] = cur;
        rotate(cur.rbegin(), cur.rbegin()+1, cur.rend());
    }

    cur = row;
    rotate(cur.begin(), cur.begin()+1, cur.end());

    for(int i = r; i < n; i++) {
        ans[i] = cur;
        rotate(cur.begin(), cur.begin()+1, cur.end());
    }

    for(string s: ans) cout << s << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}