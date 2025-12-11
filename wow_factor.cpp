#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();

    vector<int> cnt1(n), cnt2(n);

    int cur = 0, tot = 0, ans = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'v') cur++;
        else if(cur) {
            tot += cur-1;
            cur = 0;
            cnt1[i] = tot;
        } else {
            cnt1[i] = tot;
        }
    }

    cur = 0, tot = 0;

    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'v') cur++;
        else if(cur) {
            tot += cur-1;
            cur = 0;
            cnt2[i] = tot;
        } else {
            cnt2[i] = tot;
        }
    }

    for(int i = 0; i < n; i++) {
        ans += cnt1[i]*cnt2[i];
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