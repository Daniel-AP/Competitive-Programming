#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<string> sts(k);
    for(int i = 0; i < k; i++) cin >> sts[i];

    vector<int> divs;

    for(int i = 1; i*i <= n; i++) {
        if(n%i != 0) continue;
        divs.push_back(i);
        if(n/i != i) divs.push_back(n/i);
    }

    int ans = n;
    string sans = sts[0];

    for(int d: divs) {
        vector<vector<int>> cnt(d, vector<int>(26));
        vector<int> seen(26);
        int id = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                if(seen[sts[j][i]-'a'] == id) continue;
                cnt[i%d][sts[j][i]-'a']++;
                seen[sts[j][i]-'a'] = id;
            }
            id++;
        }
        bool good = true;
        for(int i = 0; i < d; i++) {
            good &= (*max_element(all(cnt[i])) >= n/d);
        }
        if(good && ans > d) {
            sans.clear();
            ans = d;
            for(int i = 0; i < d; i++) {
                int mx = *max_element(all(cnt[i]));
                for(int j = 0; j < 26; j++) {
                    if(cnt[i][j] == mx) {
                        sans += char('a'+j);
                        break;
                    }
                }
            }
        } 
    }

    for(int i = 0; i < n/ans; i++) {
        cout << sans;
    }
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