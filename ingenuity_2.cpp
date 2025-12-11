#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    array<vector<int>, 4> nsew;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'N') nsew[0].push_back(i);
        if(s[i] == 'S') nsew[1].push_back(i);
        if(s[i] == 'E') nsew[2].push_back(i);
        if(s[i] == 'W') nsew[3].push_back(i);
    }

    if((nsew[0].size())%2 != (nsew[1].size())%2 || (nsew[2].size())%2 != (nsew[3].size())%2) return void(cout << "NO" << '\n');

    string ans(n, ' ');
    
    for(int i = 0; i < 4; i++) {
        char cur = (i < 2 ? 'R' : 'H');
        for(int j = 0; j < nsew[i].size(); j++) ans[nsew[i][j]] = cur, cur = 'R'+'H'-cur;
    }

    int cnt = count(ans.begin(), ans.end(), 'R');

    if(cnt == 0 || cnt == n) return void(cout << "NO" << '\n');

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}