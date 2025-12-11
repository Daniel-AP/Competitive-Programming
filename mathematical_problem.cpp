#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    if(n == 2) return void(cout << stoll(s) << '\n');
    if(n == 3) {

        int p1 = stoll(s.substr(0, 2)), s1 = s[2]-'0';
        int s2 = s[0]-'0', p2 = stoll(s.substr(1, 2));

        cout << min({ p1*s1, p1+s1, s2*p2, s2+p2 }) << '\n';

        return;
    }

    if(count(s.begin(), s.end(), '0')) return void(cout << 0 << '\n');

    int sm = 0;
    for(int i = 0; i < n; i++) if(s[i] != '1') sm += s[i]-'0';

    int ans = INF;

    for(int i = 0; i+1 < n; i++) {
        int smm = sm;
        if(s[i] != '1') smm -= s[i]-'0';
        if(s[i+1] == '1') smm++;
        smm += 10*(s[i]-'0');
        ans = min(ans, smm);
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