#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

bool bad(vector<int>& cnts, vector<int>& cntt) {
    for(int i = 0; i < 26; i++) {
        if(cnts[i] > cntt[i]) return true;
    }
    return false;
}

void solve() {

    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    vector<int> cntt(26), cnts(26);

    for(int i = 0; i < m; i++) cntt[t[i]-'a']++;

    int l = 0, ans = 0;

    for(int r = 0; r < n; r++) {
        cnts[s[r]-'a']++;
        while(bad(cnts, cntt)) cnts[s[l++]-'a']--;
        ans += r-l+1;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}