#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<array<int, 26>> md(k);

    for(int i = 0; i < n; i++) {
        md[(i+1)%k][s[i]-'a']++;
    }

    int l = 1, r = k, ans = 0;

    while(l <= r) {

        int tot1 = (n-l)/k+1, tot2 = (n-r)/k+1;
        int best = tot1+tot2;

        for(int i = 0; i < 26; i++) {
            best = min(best, tot1+tot2-md[l%k][i]-md[r%k][i]);
        }

        if(l == r) ans += best/2;
        else ans += best;
        
        l++, r--;

    }

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