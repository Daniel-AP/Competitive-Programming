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
    string t = s;

    sort(all(t));

    vector<int> ans;

    for(int i = 0; i < n; i++) {
        if(s[i] != t[i]) ans.push_back(i);
    }

    if(is_sorted(all(s))) return void(cout << "Bob" << '\n');

    cout << "Alice" << '\n';
    cout << ans.size() << '\n';

    for(int x: ans) cout << x+1 << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}