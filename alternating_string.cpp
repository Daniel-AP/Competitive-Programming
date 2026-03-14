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

    if(n%2 == 0) {

        int ans = 0, mx = 0;
        array<int, 26> cnt{};

        for(int i = 0; i < n; i += 2) cnt[s[i]-'a']++, mx = max(mx, cnt[s[i]-'a']);
        ans += n/2-mx;
        mx = 0;
        fill(all(cnt), 0);
        for(int i = 1; i < n; i += 2) cnt[s[i]-'a']++, mx = max(mx, cnt[s[i]-'a']);
        ans += n/2-mx;

        return void(cout << ans << '\n');

    }

    int ans = INF;

    vector<array<int, 26>> pxE(n+2);

    for(int i = 1; i <= n; i++) {
        pxE[i] = pxE[i-1];
        if(i%2) continue;
        pxE[i][s[i-1]-'a']++;
    }

    vector<array<int, 26>> pxO(n+1);

    for(int i = 1; i <= n; i++) {
        pxO[i] = pxO[i-1];
        if(i%2 == 0) continue;
        pxO[i][s[i-1]-'a']++;
    }

    for(int i = 1; i <= n; i++) {

        array<int, 26> even = pxE[i-1], odd = pxO[i-1];

        for(int j = 0; j < 26; j++) even[j] += (pxO[n][j]-pxO[i][j]);
        for(int j = 0; j < 26; j++) odd[j] += (pxE[n][j]-pxE[i][j]);

        int mxE = *max_element(all(even)), mxO = *max_element(all(odd));

        ans = min(ans, n/2-mxE+n/2-mxO+1);

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